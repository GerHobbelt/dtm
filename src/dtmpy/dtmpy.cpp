#include <pybind11/pybind11.h>
#include "../dtm/dtm.hpp"

namespace py = pybind11;

PYBIND11_MODULE(dtmpy, m) {
    m.doc() = R"pbdoc(
        Module for fitting a Dynamic Topic Model.

        Classes:
            DTM
    )pbdoc";
    py::class_<DTM>(m, "DTM")
    .def(py::init<
        bool,
        int,
        std::string,
        std::string,
        std::string,
        double,
        std::string,
        std::string,
        std::string,
        int,
        double,
        double,
        int,
        double,
        double,
        int,
        double,
        double,
        double,
        double,
        double,
        double,
        int,
        int,
        int,
        int,
        int,
        std::string,
        int,
        double,
        double,
        std::string,
        int,
        std::string,
        int,
        int>(),
        R"pbdoc(
        Class for fitting a dynamic topic model. Initialize training parameters then use the Run method to train the model.

        Methods:
            fit: Fit a dynamic topic model

        Args:
           initialize_lda: If true, initialize the model with lda. default: false
           lda_max_em_iter: default: 20
           lda_model_prefix: The name of a fit model to be used for testing likelihood.  Appending "info.dat" to this should give the name of the file. default: ""
           mode: The function to perform. Can be fit, est, or time. default: "fit"
           model: The function to perform. Can be dtm or dim. default: "dtm"
           ntopics: default: -1
           outname: default: ""
           output_table: default: ""
           params_file: A file containing parameters for this run. default: "settings.txt"
           start: default: -1
           top_chain_var: default: 0.005
           top_obs_var: default: 0.5
           influence_flat_years: How many years is the influence nonzero? If nonpositive, a lognormal distribution is used.) type int32, default: -1
           influence_mean_years: How many years is the mean number of citations?) default: 20
           influence_stdev_years: How many years is the stdev number of citations?) default: 15
           max_number_time_points: Used for the influence window. default: 200
           resolution: The resolution.  Used to determine how far out the beta mean should be.) default: 1
           sigma_c: c stdev.  default: 0.05
           sigma_cv: Variational c stdev. default: 1e-6
           sigma_d: If true, use the new phi calculation. default: 0.05
           sigma_l: If true, use the new phi calculation. default: 0.05
           time_resolution: This is the number of years per time slice. default: 0.5
           rng_seed: Specifies the random seed.  If 0, seeds pseudo-randomly. default: 0
           fix_topics: Fix a set of this many topics. This amounts to fixing these  topics' variance at 1e-10. default: 0
           forward_window: The forward window for deltas. If negative, we use a beta with mean 5. default: 1
           lda_sequence_max_iter: The maximum number of iterations. default: 20
           lda_sequence_min_iter: The maximum number of iterations. default: 1
           normalize_docs: Describes how documents's wordcounts are considered for finding influence. Options are "normalize", "none", "occurrence", "log", or "log_norm".) default: "normalize"
           save_time: Save a specific time.  If -1, save all times. default: 2147483647
           lambda_convergence: Specifies the level of convergence required for lambda in the phi updates. default: 0.01
           lda_inference_max_iter: Max iterations to use LDA Inference
           alpha: default: -10
           corpus_prefix: The function to perform. Can be dtm or dim. default: ""
           end: default: -1
           heldout_corpus_prefix: default: ""
           heldout_time: A time up to (but not including) which we wish to train, and at which we wish to test. default: -1
        )pbdoc",
            py::arg("initialize_lda") = false,
            py::arg("lda_max_em_iter") = 20,
            py::arg("lda_model_prefix") = "",
            py::arg("mode") = "fit",
            py::arg("model") = "dtm",
            py::arg("ntopics") = -1.0,
            py::arg("outname") = "",
            py::arg("output_table") = "",
            py::arg("params_file") = "settings.txt",
            py::arg("start") = -1,
            py::arg("top_chain_var") = 0.005,
            py::arg("top_obs_var") = 0.5,
            py::arg("influence_flat_years") = -1,
            py::arg("influence_mean_years") = 20,
            py::arg("influence_stdev_years") = 15,
            py::arg("max_number_time_points") = 200,
            py::arg("resolution") = 1,
            py::arg("sigma_c") = 0.05,
            py::arg("sigma_cv") = 1e-6,
            py::arg("sigma_d") = 0.05,
            py::arg("sigma_l") = 0.05,
            py::arg("time_resolution") = 0.5,
            py::arg("rng_seed") = 0,
            py::arg("fix_topics") = 0,
            py::arg("forward_window") = 1,
            py::arg("lda_sequence_max_iter") = 20,
            py::arg("lda_sequence_min_iter") = 1,
            py::arg("normalize_docs") = "normalize",
            py::arg("save_time") = 2147483647,
            py::arg("lambda_convergence") = 0.01,
            py::arg("alpha") = -10,
            py::arg("corpus_prefix") = "",
            py::arg("end") = -1,
            py::arg("heldout_corpus_prefix") = "",
            py::arg("heldout_time") = -1,
            py::arg("lda_inference_max_iter") = 20)
    .def("fit", &DTM::fit,
        R"pbdoc(
        Fit the dynamic topic model to the data and output results to file.
        )pbdoc"
            );

#ifdef VERSION_INFO
    m.attr("__version__") = VERSION_INFO;
#else
    m.attr("__version__") = "dev";
#endif
}
