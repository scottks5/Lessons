#include <iostream>
#include "shape.h"
#include <vector>
#include <gsl/gsl_rng.h>
#include <memory>

const int MAX = 100;

int main(int argc, char* arv[]) {

    const gsl_rng_type * T;
    gsl_rng * r;
    gsl_rng_env_setup();
    T = gsl_rng_default;
    r = gsl_rng_alloc (T);


    std::vector<shape*> my_array;
    std::vector<shape*>::iterator it;

    std::cout << my_array.capacity() << std::endl;
    shapeFactory MyFactory;

    for(int ctr = 0; ctr<MAX; ctr++){
        double u = gsl_rng_uniform(r);
        double u1 = gsl_rng_uniform(r);
        double u2 = gsl_rng_uniform(r);
        double u3 = gsl_rng_uniform(r);

        if (u < 0.5){
            my_array.push_back(MyFactory.createSquareInstance(u1,u2,u3));
        } else {
            my_array.push_back(MyFactory.createCircleInstance(u1,u2));
        };

    };
    double total = 0;
    for (auto it = std::begin(my_array); it != std::end(my_array); ++it){
        std::cout << (*it)->m_type << " ";
        (*it)->draw();
        total = total + (*it)->m_type;
    }
    std::cout << total/MAX << std::endl;

    std::cout<< my_array.capacity() << std::endl;

    std::cout << "PAUSING" << std::endl;
    double val =0;
    std::cin >> val;
    for (auto it = std::begin(my_array); it != std::end(my_array); ++it){
        delete *it;
    }
    my_array.clear();
    my_array.shrink_to_fit();
    std::cout << my_array.capacity() << std::endl;
    std::cin >> val;

    gsl_rng_free(r);
    std::cout << total/MAX << std::endl;
    std::cin >> val;


/*    cout << "thing 1" << endl;

    my_array.push_back(square(32.3));
    cout << "thing 2" << endl;
    my_array.push_back(square(34.3));
    cout << "thing 3" << endl;

    square A = square(3.0);
    square B = square(1.2);
    square C = square(3.0,4.5,2.3);
    displayer(A);
    displayer(B);
    displayer(C);
    B = std::move(A);
    cout << "thing 4" << endl;
    displayer(A);
    displayer(B);
    displayer(C);
*/
/*    my_array.insert(my_array.begin()+1,square(33.0));
    for (it = my_array.begin(); it != my_array.end(); ++it){
        displayer(*it);
    }
*/
    return 0;
}
