//
// Created by Mark van der Broek on 01/03/2017.
//

/**
 * @brief Constructor. Read all the data from the input file into vectors.
 *
 * @param [in] file The name of the file to read the data from
 */

#include "init.ih"

using namespace std;

Init::Init(std::string &file)
:
    d_inputFile(file)
{}
