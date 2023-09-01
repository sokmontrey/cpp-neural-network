#include <gamma_net/gamma_net.h>
#include <nodeflow/nodeflow.h>
#include <matplot/matplot.h>
#include <Eigen/Dense>
#include <vector>

using namespace nodeflow;
namespace plt = matplot;

int main(){
    int layer_size = 4;
    int layer[] = {1, 4, 4, 1};

    Node x = Node::Constant(layer[0], 1, 1);

    std::vector<Node> w;
    std::vector<Node> b;

    for(int i=0; i<layer_size-1; i++){
        w.push_back(Node::Random(layer[i+1], layer[i]));
        b.push_back(Node::Random(layer[i+1]));
    }

    Mul m1{&w[0], &x};
    Add z1{&m1, &b[0]};
    Tanh h1{&z1};

    Mul m2{&w[1], &h1};
    Add z2{&m2, &b[1]};
    Tanh h2{&z2};

    Mul m3{&w[2], &h2};
    Add z3{&m3, &b[2]};
    Tanh o{&z3};

    Node t = Node::Constant(1, 1, 1);

    Subtract s{&o, &t};
    Pow s2({&s}, 2);

    return 0;
}
