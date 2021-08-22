# dtmpy

A Python module for doing fast Dynamic Topic Modeling.

This module wraps the original C/C++ code by David M. Blei and Sean M. Gerrish.

I've refactored the original code to wrap the main function call in a class `DTM` that has Python bindings. Other code changes are listed below.

## Usage

Reference the `dtmpy.DTM` docstring for all possible keyword arguments.

```python
import dtmpy

# Initialize DTM model flags
dtm = dtmpy.DTM(corpus_prefix="model_inputs/file_prefix", output_name="model_outputs", n_topics=10)

# Fit the model and write outputs from bag-of-words corpus and timestamps
dtm.fit(my_corpus, n_docs_per_timestamp)

topic_mixtures = dtm.read_topic_mixtures()
```

## Install

First install the following libraries:

- `libgsl-dev`
- `pybind11-dev`

Then install the package from the files in this repo:

```
git clone https://github.com/jeffmm/dtmpy
cd dtmpy
pip install .
```

## Model inputs

The Dynamic Topic Model takes two files as inputs:

- `foo-mult.dat` (the `mult` file)
- `foo-seq.dat` (the `seq` file)

If the above files are in the directory `bar` relative to the working directory, then the `corpus_prefix` argument will be `bar/foo`.

If the dataset consists of `N` docs, then the `mult` file is an `N`-length file where line `i` lists the number of unique words in document `i` and the `index:count` for each word in the document, like so:

```
unique_word_count_doc_1 index_11:count_11 index_12:count_12 ... index_1n:count_1n
unique_word_count_doc_2 index_21:count_21 index_22:count_22 ...
...
unique_word_count_doc_N index_N1:count_N1 index_N2:count_N2 ...
```

Where each word index corresponds to a unique word in the vocabulary (ie listed in a dictionary somewhere)

The order of the docs in `mult` should be chronological, in order to correspond to the documents numbered in the `seq` file.

The `seq` file gives the number of documents that correspond to each time slice in the DTM, and is of the form

```
n_times
number_docs_time_1
number_docs_time_2
...
number_docs_time_n_times
```

Two additional files that are useful to have somewhere are:

- file with all of the words in the vocabulary, arranged in the same order as the word indices
- a file with information on each of the documents, arranged in the same order as the docs in the `mult` file.

## Model outputs

The model outputs the following files to the directory specified by the `outname` argument.

- `topic-xxx-var-e-log-prob.dat`: the e-betas (word distributions) for topic xxx for all times. This is in row-major form, e.g. (in R):

```r
a = scan("topic-002-var-e-log-prob.dat")
b = matrix(a, ncol=10, byrow=TRUE)

# The probability of term 100 in topic 2 at time 3:
exp(b[100, 3])
```

- `gam.dat`: The gammas associated with each document. Divide these by the sum for each document to get expected topic mixtures.

```r
a = scan("gam.dat")
b = matrix(a, ncol=10, byrow=TRUE)
rs = rowSums(b)
e.theta = b / rs

# Proportion of topic 5 in document 3:
e.theta[3, 5]
```

If you are running this software in "dim" mode to find document influence, it will also create the following files:

- `influence_time-yyy` : the influence of documents at time yyy for each topic, where time is based on in your `seq` file and the document index is given by the ordering of documents in the `mult` file.

```r
a = scan("influence-time-010")
b = matrix(a, ncol=10, byrow=TRUE)

# The influence of the 2nd document on topic 5:

b[2, 5]
```

## Changes to the original code

- Refactored original `main` function to be `fit` method of class `DTM`
- Removed dependence of `gflags` and converted global flags to use extern variables that are initialized by `DTM`.
- Added Python bindings to `DTM` class using `pybind11`
- Better error handling to prevent commands like `exit` from crashing the Python kernel
- Better use of `const` to limit number of compiler warnings
- More sane defaults:
  - changed `corpus_prefix` and `outname` to be required arguments
  - changed `ntopics` from -1.0 to 10
  - changed `alpha` from -10 to 0.01
  - changed `lda_sequence_min_iter` from 1 to 3
  - changed `initialize_lda` flag to true

# Dynamic Topic Models and the Document Influence Model

This implements topics that change over time (Dynamic Topic Models) and a model of how individual documents predict that change.

This code is the result of work by David M. Blei and Sean M. Gerrish.

(C) Copyright 2006, David M. Blei

(C) Copyright 2011, Sean M. Gerrish

It includes software corresponding to models described in the
following papers:

[1] [D. Blei and J. Lafferty. Dynamic topic models. In
Proceedings of the 23rd International Conference on Machine Learning, 2006.](http://www.cs.columbia.edu/~blei/papers/BleiLafferty2006a.pdf)

[2] [S. Gerrish and D. Blei. A Language-based Approach to Measuring
Scholarly Impact. In Proceedings of the 27th International Conference
on Machine Learning, 2010.](http://www.cs.columbia.edu/~blei/papers/GerrishBlei2010.pdf)

These files are part of DIM.

DIM is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.

DIM is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA

---
