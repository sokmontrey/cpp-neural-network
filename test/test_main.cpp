#include <gamma_net/gamma_net.h>
#include <nodeflow/nodeflow.h>
#include <matplot/matplot.h>
#include <Eigen/Dense>
#include <vector>

using namespace nodeflow;

int main(){
    using namespace matplot;
    auto x_train = linspace(0, 2*pi, 50);
    auto y_train = transform(x_train, [](double x){ return sin(x); });

    int layer_size = 4;
    int layer[] = {1, 20, 20, 1};

    Node x = Node::Constant(layer[0], 1, 1);

    std::vector<Node> w;
    std::vector<Node> b;

    for(int i=0; i<layer_size-1; i++){
        w.push_back(Node::Random(layer[i+1], layer[i]));
        b.push_back(Node::Random(layer[i+1]));
    }

    Mul m1{&w[0], &x};
    Add z1{&m1, &b[0]};
    ReLU h1{&z1};

    Mul m2{&w[1], &h1};
    Add z2{&m2, &b[1]};
    ReLU h2{&z2};

    Mul m3{&w[2], &h2};
    Add z3{&m3, &b[2]};

    Node one = Node::Constant(1, 1, 1);
    one.constant();

    // ScalarMul o1(&z3, 2);
    // Sigmoid o2(&o1);
    // ScalarMul o3(&o2, 2);
    // Subtract o(&o3, &one);
    Tanh o{&z3};

    Node t = Node::Constant(1, 1, 1);

    Subtract s{&o, &t};
    Pow s2({&s}, 2);

    Sum s3(&s2);

    ScalarDiv err(&s3, 1);

    err.forward();
    err.finished();

    auto p_train = linspace(0, 1, x_train.size());
    double learning_rate = 0.01;

    for(int ep=0; ep<1000; ep++){
        double lost = 0;

        for(int i=0; i<x_train.size(); i++){
            double input = x_train[i];
            double target = y_train[i];

            x(0,0) = input;
            t(0,0) = target;

            // Error 
            lost += err.forward()(0,0);

            // Backward
            err.backward();
            for(int j=0; j<w.size(); j++){
                w[j]() -= learning_rate * w[j].getGrad();
                b[j]() -= learning_rate * b[j].getGrad();
            }

            err.reset();
        }
        lost /= x_train.size();
        std::cout << "ep: " << ep << " lost: " << lost << std::endl;

    }

    for(int i=0; i<x_train.size(); i++){
        double input = x_train[i];
        double target = y_train[i];

        x(0,0) = input;
        t(0,0) = target;

        // Predict
        double prediction = o.forward()(0,0);
        p_train[i] = prediction;
        o.reset();
    }

    plot(y_train);
    hold(on);
    plot(p_train);
    show();

    return 0;
}
