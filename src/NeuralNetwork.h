/*
    Copyright (c) 2016, 2017, 2018, 2019 Joao Salavisa <joao.salavisa@gmail.com>.

    Permission is hereby granted, free of charge, to any person obtaining
    a copy of this software and associated documentation files (the "Software"),
    to deal in the Software without restriction, including without limitation
    the rights to use, copy, modify, merge, publish, distribute, sublicense,
    and/or sell copies of the Software, and to permit persons to whom the Software
    is furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
    EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
    OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
    IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
    CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
    TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
    OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <list>
#include <iterator>

#include "Neuron.h"
#include "NetworkConfiguration.h"

class NeuralNetwork {
  private:
    int n_inputs, n_outputs;
    int n_hidden_layers, n_neuron_hidden;
    list<list<Neuron *> > m_hidden;
    list<Neuron *> m_output; 
  
  public:
    /* contstuctor */
    NeuralNetwork(int inputs, int outputs, int hidden_layers, int neuron_hidden);
    NeuralNetwork(NetworkConfiguration * configuration);
    ~NeuralNetwork();

    void init();
    
    /* feed the network forward */
    vector<float> feedForward(vector<float> input);
    
    /* backward pass to update the weights based on the current error */
    double backwardPass(vector<float> output);

    /* train the network given a specific input and output */
    double train(vector<float> input, vector<float> output);
    
    /* load weights */
    void loadWeights(vector<float> weights);

    string toString();
    
  private:
    vector<float> evaluateHiddenLayers(vector<float> inputs);
    vector<float> evaluateOutputLayer(vector<float> hidden_output);
};

#endif
