/* Copyright 2018-2018 University Corporation for Atmospheric
   Research/Unidata. */

/**
 * @file This header file containsfilter related  macros, types, and prototypes for
 * the filter code in libnczarr. This header should not be included in
 * code outside libnczarr.
 *
 * @author Dennis Heimbigner
 */

#ifndef ZFILTER_H
#define ZFILTER_H

/* zfilter.c */
/* Dispatch functions are also in zfilter.c */
/* Filterlist management */

/*Mnemonic*/
#define ENCODING 1

/* list of environment variables to check for plugin roots */
#define plugin_env "HDF5_PLUGIN_PATH"
#define plugin_dir_unix "/usr/local/hdf5/plugin"
#define plugin_dir_win "%s/hdf5/lib/plugin"
#define win32_root_env "ALLUSERSPROFILE"

/*
Return a NULL terminated vector of pointers to instances of ''NCZ_codec_t''.
The value returned is actually of type ''NCZ_codec_t**'',
but is of type ''void*'' to allow for extensions.
The list of returned items are used to try to provide defaults
for any HDF5 filters that have no corresponding Codec.
This is for internal use only.
*/
typedef void* (*NCZ_codec_info_defaults_proto)(void);

/* Opaque */
struct NCZ_Filter;

int NCZ_filter_initialize(void);
int NCZ_filter_finalize(void);
int NCZ_addfilter(NC_FILE_INFO_T*, NC_VAR_INFO_T* var, unsigned int id, size_t nparams, const unsigned int* params);
int NCZ_filter_setup(NC_VAR_INFO_T* var);
int NCZ_filter_freelist(NC_VAR_INFO_T* var);
int NCZ_codec_freelist(NCZ_VAR_INFO_T* zvar);
int NCZ_applyfilterchain(const NC_FILE_INFO_T*, NC_VAR_INFO_T*, NClist* chain, size_t insize, void* indata, size_t* outlen, void** outdata, int encode);
int NCZ_filter_jsonize(const NC_FILE_INFO_T*, const NC_VAR_INFO_T*, struct NCZ_Filter* filter, struct NCjson**);
int NCZ_filter_build(const NC_FILE_INFO_T*, NC_VAR_INFO_T* var, const NCjson* jfilter);
int NCZ_codec_attr(const NC_VAR_INFO_T* var, size_t* lenp, void* data);
	    
#endif /*ZFILTER_H*/
