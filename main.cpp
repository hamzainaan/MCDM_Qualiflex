#include "defs.hpp"

int main(int argc, char* argv[]) {

    //User input.
    u alt_temp, cr_temp;

    std::cout << "The number of alternatives: ";
    std::cin >> alt_temp;

    //Assertion.
    assert(alt_temp > 0);

    //User input for alternatives and attributes.
    std::vector<alt> alternatives(alt_temp);
    for(u i=0; i<alt_temp; i++) {

        alternatives[i].alt_name = "A" + std::to_string(i+1);

        std::cout << "How many attributes does " << alternatives[i].alt_name << " have?: ";
        std::cin >> cr_temp;

        //Resize and user input.
        alternatives[i].alt_cr.resize(cr_temp);

        for(u j=0; j<cr_temp; j++) {
            std::cout << j+1 << ". attribute for " << alternatives[i].alt_name << ": ";
            std::cin >> alternatives[i].alt_cr[j];
        }
    }

    //Create vectors.
    std::vector<u> weights(alternatives[0].alt_cr.size()), bounds(alternatives[0].alt_cr.size());

    for(u i=0; i<alternatives[0].alt_cr.size(); i++) {

        std::cout << "Weight for attribute " << i+1 << ": ";
        std::cin >> weights[i];

        std::cout << "Bound for attribute " << i+1 << ": ";
        std::cin >> bounds[i];
    }

    //Evaluate.
    std::vector<alt> magic = evaluate(alternatives, weights, bounds);

    std::cout << "Best alternative(s) is/are: ";
    for(u i=0; i<magic.size(); i++) {
        std::cout << magic[i].alt_name << (i == magic.size()-1 ? "." : ", ");
    }

    std::cout << std::endl;

    return 0;
}