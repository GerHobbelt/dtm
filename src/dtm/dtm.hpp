#ifndef DTMH
#define DTMH

#include <stdlib.h>
#include <string>
#include "data.hpp"
#include "lda-seq.hpp"
#include "lda.hpp"
#include <gsl/gsl_matrix.h>

class DTM {
    public:
        DTM(std::string corpus_prefix, // The function to perform. Can be dtm or dim. type: string, default: ""
            std::string outname, // type: string, default: ""
            bool initialize_lda = true, // If true, initialize the model with lda. type: bool, default: false
            int lda_max_em_iter = 20, // type: int32 default: 20
            std::string lda_model_prefix = "", // The name of a fit model to be used for testing likelihood.  Appending "info.dat" to this should give the name of the file. type: string, default: ""
            std::string mode = "fit", // The function to perform. Can be fit, est, or time. type: string, default: "fit"
            std::string model = "dtm", // The function to perform. Can be dtm or dim. type: string, default: "dtm"
            double ntopics = 10, // type: double, default: -1
            std::string output_table = "", // type: string default: ""
            std::string params_file = "settings.txt", // A file containing parameters for this run. type: string, default: "settings.txt"
            int start = -1, // type: int32 default: -1
            double top_chain_var = 0.005, // type: double default: 0.005
            double top_obs_var = 0.5, // type: double default: 0.5
            int influence_flat_years = -1, // How many years is the influence nonzero? If nonpositive, a lognormal distribution is used.) type int32, default: -1
            double influence_mean_years = 20, // How many years is the mean number of citations?) type: double, default: 20
            double influence_stdev_years = 15, // How many years is the stdev number of citations?) type: double, default: 15
            int max_number_time_points = 200, // Used for the influence window. type: int32, default: 200
            double resolution = 1, // The resolution.  Used to determine how far out the beta mean should be.) type: double, default: 1
            double sigma_c = 0.05, //  c stdev.  type: double, default: 0.05
            double sigma_cv = 1e-6, // Variational c stdev. type: double, default: 1e-6
            double sigma_d = 0.05, //  If true, use the new phi calculation. type: double, default: 0.05
            double sigma_l = 0.05, //  If true, use the new phi calculation. type: double, default: 0.05
            double time_resolution = 0.5, // This is the number of years per time slice. type: double, default: 0.5
            int rng_seed = 0, // Specifies the random seed.  If 0, seeds pseudo-randomly. type: int64, default: 0
            int fix_topics = 0, // Fix a set of this many topics. This amounts to fixing these  topics' variance at 1e-10. type: int32, default: 0
            int forward_window = 1, // The forward window for deltas. If negative, we use a beta with mean 5. type: int32, default: 1
            int lda_sequence_max_iter = 20, // (The maximum number of iterations.) type: int32, default: 20
            int lda_sequence_min_iter = 3, // (The maximum number of iterations.) type: int32, default: 1
            std::string normalize_docs = "normalize", // (Describes how documents's wordcounts are considered for finding influence. Options are "normalize", "none", "occurrence", "log", or "log_norm".) type: string, default: "normalize"
            int save_time = 2147483647, // (Save a specific time.  If -1, save all times.) type: int32, default: 2147483647
            double lambda_convergence = 0.01, // (Specifies the level of convergence required for lambda in the phi updates.) type: double, default: 0.01
            double alpha = 0.01, // type: double default: -10
            int end = -1, // type: int32 default: -1
            std::string heldout_corpus_prefix = "", // type: string default: ""
            int heldout_time = -1, // A time up to (but not including) which we wish to train, and at which we wish to test. type: int32, default: -1
            int lda_inference_max_iter = 25
            );
        void fit();

    private:
        void fit_dtm(int min_time, int max_time);

};

typedef struct dtm_fit_params
{
    char* datafile;
    char* outname;
    char* heldout;
    int start;
    int end;
    int ntopics;
    int lda_max_em_iter;
    double top_obs_var;
    double top_chain_var;
    double alpha;
} dtm_fit_params;

#endif
