#include "defs.hpp"

//Evaluate the best alternatives based on Qualiflex Method.
std::vector<alt> evaluate(std::vector<alt>& alternatives, std::vector<u>& weights, std::vector<u>& bounds) {

    //Store the each alternatives' score.
    std::vector<u> results(alternatives.size(), 0);

    //Iterate over alternatives.
    for(u i=0; i<alternatives.size(); i++) {
        for(u j=0; j<alternatives[0].alt_cr.size(); j++) {
            results[i] += (alternatives[i].alt_cr[j] >= bounds[j]) ? weights[j] : 0;
        }
    }

    std::vector<u> indxs;
    //Find max results and determine.
    for(u i=0; i<alternatives.size(); i++) {
        if(results[i] == *std::max_element(results.begin(), results.end())) {
            indxs.push_back(i);
        }
    }

    std::vector<alt> choose_best;
    for(u i=0; i<indxs.size(); i++) {
        choose_best.push_back(alternatives[indxs[i]]);
    }

    //Return best alternatives.
    return choose_best;
}