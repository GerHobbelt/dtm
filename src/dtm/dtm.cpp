// Authors: David Blei (blei@cs.princeton.edu)
//          Sean Gerrish (sgerrish@cs.princeton.edu)
//
// Copyright 2011 Sean Gerrish and David Blei
// All Rights Reserved.
//
// See the README for this package for details about modifying or
// distributing this software.

#include "dtm.hpp"


// Flags from data.c
int FLAGS_influence_flat_years = -1; // How many years is the influence nonzero? If nonpositive, a lognormal distribution is used.) type int32, default: -1
double FLAGS_influence_mean_years = 20; // How many years is the mean number of citations?) type: double, default: 20
double FLAGS_influence_stdev_years = 15; // How many years is the stdev number of citations?) type: double, default: 15
int FLAGS_max_number_time_points = 200; // Used for the influence window. type: int32, default: 200
double FLAGS_resolution = 1; // The resolution.  Used to determine how far out the beta mean should be.) type: double, default: 1
double FLAGS_sigma_c = 0.05; //  c stdev.  type: double, default: 0.05
double FLAGS_sigma_cv = 1e-6; // Variational c stdev. type: double, default: 1e-6
double FLAGS_sigma_d = 0.05; //  If true, use the new phi calculation. type: double, default: 0.05
double FLAGS_sigma_l = 0.05; //  If true, use the new phi calculation. type: double, default: 0.05
double FLAGS_time_resolution = 0.5; // This is the number of years per time slice. type: double, default: 0.5

// Flags from gsl-wrappers.c:
int FLAGS_rng_seed = 0; // Specifies the random seed.  If 0, seeds pseudo-randomly. type: int64, default: 0

// Flags from lda-seq.c:
int FLAGS_fix_topics = 0; // Fix a set of this many topics. This amounts to fixing these  topics' variance at 1e-10. type: int32, default: 0
int FLAGS_forward_window = 1; // The forward window for deltas. If negative, we use a beta with mean 5. type: int32, default: 1
int FLAGS_lda_sequence_max_iter = 20; // (The maximum number of iterations.) type: int32, default: 20
int FLAGS_lda_sequence_min_iter = 1; // (The maximum number of iterations.) type: int32, default: 1
std::string FLAGS_normalize_docs = "normalize"; // (Describes how documents's wordcounts are considered for finding influence. Options are "normalize", "none", "occurrence", "log", or "log_norm".) type: string, default: "normalize"
int FLAGS_save_time = 2147483647; // (Save a specific time.  If -1, save all times.) type: int32, default: 2147483647

// Flags from lda.c:
double FLAGS_lambda_convergence = 0.01; // (Specifies the level of convergence required for lambda in the phi updates.) type: double, default: 0.01
int FLAGS_lda_inference_max_iter = 25;

// Flags from main.c:
double FLAGS_alpha = 0.01; // type: double default: 0.01
std::string FLAGS_corpus_prefix = ""; // The function to perform. Can be dtm or dim. type: string, default: ""
int FLAGS_end = -1; // type: int32 default: -1
std::string FLAGS_heldout_corpus_prefix = ""; // type: string default: ""
int FLAGS_heldout_time = -1; // A time up to (but not including) which we wish to train, and at which we wish to test. type: int32, default: -1
bool FLAGS_initialize_lda = true; // If true, initialize the model with lda. type: bool, default: false
int FLAGS_lda_max_em_iter = 20; // type: int32 default: 20
std::string FLAGS_lda_model_prefix = ""; // The name of a fit model to be used for testing likelihood.  Appending "info.dat" to this should give the name of the file. type: string, default: ""
std::string FLAGS_mode = "fit"; // The function to perform. Can be fit, est, or time. type: string, default: "fit"
std::string FLAGS_model = "dtm"; // The function to perform. Can be dtm or dim. type: string, default: "dtm"
double FLAGS_ntopics = 10; // type: double, default: 10
std::string FLAGS_outname = ""; // type: string, default: ""
std::string FLAGS_output_table = ""; // type: string default: ""
std::string FLAGS_params_file = "settings.txt"; // A file containing parameters for this run. type: string, default: "settings.txt"
int FLAGS_start = -1; // type: int32 default: -1
double FLAGS_top_chain_var = 0.005; // type: double default: 0.0050000000000000001
double FLAGS_top_obs_var = 0.5; // type: double default: 0.5


DTM::DTM(
    std::string corpus_prefix,
    std::string outname,
    bool initialize_lda,
    int lda_max_em_iter,
    std::string lda_model_prefix,
    std::string mode,
    std::string model,
    double ntopics,
    std::string output_table,
    std::string params_file,
    int start,
    double top_chain_var,
    double top_obs_var,
    int influence_flat_years,
    double influence_mean_years,
    double influence_stdev_years,
    int max_number_time_points,
    double resolution,
    double sigma_c,
    double sigma_cv,
    double sigma_d,
    double sigma_l,
    double time_resolution,
    int rng_seed,
    int fix_topics,
    int forward_window,
    int lda_sequence_max_iter,
    int lda_sequence_min_iter,
    std::string normalize_docs,
    int save_time,
    double lambda_convergence,
    double alpha,
    int end,
    std::string heldout_corpus_prefix,
    int heldout_time,
    int lda_inference_max_iter
    )
{
    FLAGS_influence_flat_years = influence_flat_years;
    FLAGS_influence_mean_years = influence_mean_years;
    FLAGS_influence_stdev_years = influence_stdev_years;
    FLAGS_max_number_time_points = max_number_time_points;
    FLAGS_resolution = resolution;
    FLAGS_sigma_c = sigma_c;
    FLAGS_sigma_cv = sigma_cv;
    FLAGS_sigma_d = sigma_d;
    FLAGS_sigma_l = sigma_l;
    FLAGS_time_resolution = time_resolution;
    FLAGS_rng_seed = rng_seed;
    FLAGS_fix_topics = fix_topics;
    FLAGS_forward_window = forward_window;
    FLAGS_lda_sequence_max_iter = lda_sequence_max_iter;
    FLAGS_lda_sequence_min_iter = lda_sequence_min_iter;
    FLAGS_normalize_docs = normalize_docs;
    FLAGS_save_time = save_time;
    FLAGS_lambda_convergence = lambda_convergence;
    FLAGS_alpha = alpha;
    FLAGS_corpus_prefix = corpus_prefix;
    FLAGS_end = end;
    FLAGS_heldout_corpus_prefix = heldout_corpus_prefix;
    FLAGS_heldout_time = heldout_time;
    FLAGS_initialize_lda = initialize_lda;
    FLAGS_lda_max_em_iter = lda_max_em_iter;
    FLAGS_lda_model_prefix = lda_model_prefix;
    FLAGS_mode = mode;
    FLAGS_model = model;
    FLAGS_ntopics = ntopics;
    FLAGS_outname = outname;
    FLAGS_output_table = output_table;
    FLAGS_params_file = params_file;
    FLAGS_start = start;
    FLAGS_top_chain_var = top_chain_var;
    FLAGS_top_obs_var = top_obs_var;
    FLAGS_lda_inference_max_iter = lda_inference_max_iter;
}

void DTM::fit() {
    try {
      // Initialize the flag objects.
      //    InitFlags(argc, argv);
      // google::ParseCommandLineFlags(&argc, &argv, 0);

        // usage: main (sums corpus_sequence|fit param|time params)

        // Create empty log file
        init_log();

        // mode for spitting out document sums
        if (FLAGS_mode == "sums") {

            corpus_seq_t* c = read_corpus_seq(FLAGS_corpus_prefix.c_str());
            outlog("Tried to read corpus %s", FLAGS_corpus_prefix.c_str());
            int d, t;
            for (t = 0; t < c->len; t++) {
                int sum = 0;
                for (d = 0; d < c->corpus[t]->ndocs; d++) {
                    sum += c->corpus[t]->doc[d]->total;
                }
                outlog("%d\n", sum);
            }
        }

        // mode for fitting a dynamic topic model

        if (FLAGS_mode == "fit") {
          fit_dtm(0, FLAGS_heldout_time - 1);
        }

        // mode for analyzing documents through time according to a DTM

        if (FLAGS_mode == "time") {
            // read parameters
            // load corpus and model based on information from params
            corpus_seq_t* data = read_corpus_seq(FLAGS_heldout_corpus_prefix.c_str());
            lda_seq* model = read_lda_seq(FLAGS_lda_model_prefix.c_str(),
                          data);
            // initialize the table (D X OFFSETS)

            int d;
            double** table = (double**) malloc(sizeof(double*) * data->len);

            for (int t = 0; t < data->len; t++) {
                table[t] = (double*) malloc(sizeof(double) * data->corpus[t]->ndocs);
                for (d = 0; d < data->corpus[t]->ndocs; d++) {
                    table[t][d] = -1;  // this should be NAN
                }
            }

            // set up the LDA model to be populated

            lda* lda_model = new_lda_model(model->ntopics, model->nterms);

            lda_post post;
            int max_nterms = compute_max_nterms(data);
            post.phi = gsl_matrix_calloc(max_nterms, model->ntopics);
            post.log_phi = gsl_matrix_calloc(max_nterms, model->ntopics);
            post.gamma = gsl_vector_calloc(model->ntopics);
            post.lhood = gsl_vector_calloc(model->ntopics);
            post.model = lda_model;

            // compute likelihoods for each model

            for (int t = 0; t < data->len; t++) {
                make_lda_from_seq_slice(lda_model, model, t);
                for (d = 0; d < data->corpus[t]->ndocs; d++) {
                    post.doc = data->corpus[t]->doc[d];
                    double likelihood = fit_lda_post(d, t, &post, model,
                             NULL,
                             NULL, NULL, NULL);
                    table[t][d] = post.doc->log_likelihood;
                }
            }
            char tmp_string[400];
            sprintf(tmp_string, "%s-heldout_post.dat", FLAGS_outname.c_str());
            FILE* post_file = fopen(tmp_string, "w");
            for (int t=0; t < data->len; ++t) {
                if (data->corpus[t]->ndocs >= 0) {
                    fprintf(post_file, "%f", table[t][0]);
                }
                for (int d = 1; d < data->corpus[t]->ndocs; ++d) {
                    fprintf(post_file, ",%f", table[t][d]);
                }
                fprintf(post_file, "\n");
            }
            // !!! write out table
        }
    }
    catch (const char *err) {
		outlog("Exception occurred: %s", err);
    }
    return;
}

void DTM::fit_dtm(int min_time, int max_time)
{
    char name[400];

    // make the directory for this fit
    char run_dir[400];
    sprintf(run_dir, "%s/", FLAGS_outname.c_str());
    if (!directory_exist(run_dir)) {
      make_directory(run_dir);
    }

    // initialize (a few iterations of LDA fitting)
    outlog("%s","### INITIALIZING MODEL FROM LDA ###\n");

    outlog("data file: %s\n", FLAGS_corpus_prefix.c_str());
    corpus_t* initial_lda_data = read_corpus(FLAGS_corpus_prefix.c_str());

    gsl_matrix* topics_ss;
    // !!! make this an option
    if (FLAGS_initialize_lda) {
      lda* lda_model = new_lda_model(FLAGS_ntopics, initial_lda_data->nterms);
      gsl_vector_set_all(lda_model->alpha, FLAGS_alpha);
      
      lda_suff_stats* lda_ss = new_lda_suff_stats(lda_model);
      // initialize_lda_ss_from_data(initial_lda_data, lda_ss);
      initialize_lda_ss_from_random(initial_lda_data, lda_ss);
      // sgerrish: Why do we only define the topics once?
      lda_m_step(lda_model, lda_ss);
      
      sprintf(name, "%s/initial-lda", run_dir);
      // TODO(sgerrish): Fix this.  This was originally hardcoded to 1.
      lda_em(lda_model, lda_ss, initial_lda_data, FLAGS_lda_max_em_iter, name);
      sprintf(name, "%s/initial-lda-ss.dat", run_dir);
      
      write_lda_suff_stats(lda_ss, name);
      topics_ss = lda_ss->topics_ss;
    } else {
      outlog("loading %d terms..\n", initial_lda_data->nterms);
      topics_ss = gsl_matrix_calloc(initial_lda_data->nterms, FLAGS_ntopics);
      sprintf(name, "%s/initial-lda-ss.dat", FLAGS_outname.c_str());
      mtx_fscanf(name, topics_ss);
    }

    // fprintf(stderr, "fitting.. \n");
    // estimate dynamic topic model

    outlog("\n%s\n","### FITTING DYNAMIC TOPIC MODEL ###");

    corpus_seq_t* data_full = read_corpus_seq(FLAGS_corpus_prefix.c_str());

    corpus_seq_t* data_subset;
    if (max_time >= 0) {
      // We are training on a subset of the data.
      assert(max_time > min_time
	     && min_time >= 0
	     && max_time < data_full->len);
      data_subset = (corpus_seq_t*) malloc(sizeof(corpus_seq_t));
      data_subset->len = max_time - min_time + 1;
      data_subset->nterms = data_full->nterms;
      data_subset->corpus = (corpus_t**) malloc(
        sizeof(corpus_t*) * data_subset->len);
      int ndocs = 0;
      for (int i=min_time; i < max_time; ++i) {
	corpus_t* corpus = data_full->corpus[i];
	data_subset->corpus[i - min_time] = corpus;
	ndocs += corpus->ndocs;
      }
      data_subset->max_nterms = compute_max_nterms(data_subset);
      data_subset->ndocs = ndocs;
    } else {
      // Use the entire dataset.
      data_subset = data_full;
    }
    
    lda_seq* model_seq = new_lda_seq(data_subset,
				     data_subset->nterms,
				     data_subset->len,
				     FLAGS_ntopics);
    init_lda_seq_from_ss(model_seq,
                         FLAGS_top_chain_var,
                         FLAGS_top_obs_var,
                         FLAGS_alpha,
                         topics_ss);

    fit_lda_seq(model_seq, data_subset, NULL, run_dir);

    if (max_time < 0) {
      return;
    }

    // Now find the posterior likelihood of the next time slice
    // using the most-recently-known time slice.
    lda* lda_model = new_lda_model(model_seq->ntopics, model_seq->nterms);
    make_lda_from_seq_slice(lda_model, model_seq, max_time - 1);

    lda_post post;
    int max_nterms = compute_max_nterms(data_full);
    post.phi = gsl_matrix_calloc(max_nterms, model_seq->ntopics);
    post.log_phi = gsl_matrix_calloc(max_nterms, model_seq->ntopics);
    post.gamma = gsl_vector_calloc(model_seq->ntopics);
    post.lhood = gsl_vector_calloc(model_seq->ntopics);
    post.model = lda_model;
    post.doc_weight = NULL;

    int d;
    double* table = (double*) malloc(sizeof(double) * data_full->corpus[max_time]->ndocs);

    for (d = 0; d < data_full->corpus[max_time]->ndocs; d++)
      {
	post.doc = data_full->corpus[max_time]->doc[d];
	table[d] = fit_lda_post(d, max_time, &post, NULL, NULL,
				NULL, NULL, NULL);
      }
    char tmp_string[400];
    sprintf(tmp_string, "%s-heldout_post_%d.dat", FLAGS_outname.c_str(),
	    max_time);
    FILE* post_file = fopen(tmp_string, "w");
    for (int d = 0; d < data_full->corpus[max_time]->ndocs; ++d)
      {
	fprintf(post_file, "%f\n", table[d]);
      }
}

