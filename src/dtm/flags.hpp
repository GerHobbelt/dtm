#ifndef DTM_FLAGS_HPP
#define DTM_FLAGS_HPP

#include <string>

// Flags from data.c
extern int FLAGS_influence_flat_years; // How many years is the influence nonzero? If nonpositive, a lognormal distribution is used.) type int32, default: -1
extern double FLAGS_influence_mean_years; // How many years is the mean number of citations?) type: double, default: 20
extern double FLAGS_influence_stdev_years; // How many years is the stdev number of citations?) type: double, default: 15
extern int FLAGS_max_number_time_points; // Used for the influence window. type: int32, default: 200
extern double FLAGS_resolution; // The resolution.  Used to determine how far out the beta mean should be.) type: double, default: 1
extern double FLAGS_sigma_c; //  c stdev.  type: double, default: 0.05
extern double FLAGS_sigma_cv; // Variational c stdev. type: double, default: 1e-6
extern double FLAGS_sigma_d; //  If true, use the new phi calculation. type: double, default: 0.05
extern double FLAGS_sigma_l; //  If true, use the new phi calculation. type: double, default: 0.05
extern double FLAGS_time_resolution; // This is the number of years per time slice. type: double, default: 0.5

// Flags from gsl-wrappers.c:
extern int FLAGS_rng_seed; // Specifies the random seed.  If 0, seeds pseudo-randomly. type: int64, default: 0

// Flags from lda-seq.c:
extern int FLAGS_fix_topics; // Fix a set of this many topics. This amounts to fixing these  topics' variance at 1e-10. type: int32, default: 0
extern int FLAGS_forward_window; // The forward window for deltas. If negative, we use a beta with mean 5. type: int32, default: 1
extern int FLAGS_lda_sequence_max_iter; // (The maximum number of iterations.) type: int32, default: 20
extern int FLAGS_lda_sequence_min_iter; // (The maximum number of iterations.) type: int32, default: 1
extern std::string FLAGS_normalize_docs; // (Describes how documents's wordcounts are considered for finding influence. Options are "normalize", "none", "occurrence", "log", or "log_norm".) type: string, default: "normalize"
extern int FLAGS_save_time; // (Save a specific time.  If -1, save all times.) type: int32, default: 2147483647

// Flags from lda.c:
extern double FLAGS_lambda_convergence; // (Specifies the level of convergence required for lambda in the phi updates.) type: double, default: 0.01
extern int FLAGS_lda_inference_max_iter;

// Flags from main.c:
extern double FLAGS_alpha; // type: double default: -10
extern std::string FLAGS_corpus_prefix; // The function to perform. Can be dtm or dim. type: string, default: ""
extern int FLAGS_end; // type: int32 default: -1
extern std::string FLAGS_heldout_corpus_prefix; // type: string default: ""
extern int FLAGS_heldout_time; // A time up to (but not including) which we wish to train, and at which we wish to test. type: int32, default: -1
extern bool FLAGS_initialize_lda; // If true, initialize the model with lda. type: bool, default: false
extern int FLAGS_lda_max_em_iter; // type: int32 default: 20
extern std::string FLAGS_lda_model_prefix; // The name of a fit model to be used for testing likelihood.  Appending "info.dat" to this should give the name of the file. type: string, default: ""
extern std::string FLAGS_mode; // The function to perform. Can be fit, est, or time. type: string, default: "fit"
extern std::string FLAGS_model; // The function to perform. Can be dtm or dim. type: string, default: "dtm"
extern double FLAGS_ntopics; // type: double, default: -1
extern std::string FLAGS_outname; // type: string, default: ""
extern std::string FLAGS_output_table; // type: string default: ""
extern std::string FLAGS_params_file; // A file containing parameters for this run. type: string, default: "settings.txt"
extern int FLAGS_start; // type: int32 default: -1
extern double FLAGS_top_chain_var; // type: double default: 0.0050000000000000001
extern double FLAGS_top_obs_var; // type: double default: 0.5

#endif
