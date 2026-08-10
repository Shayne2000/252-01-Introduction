#include "api_bridge_lab.h"

#include <ctype.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int modern_parse_year(const char *record, int *out_year) {
    const char *colon = strchr(record, ':');
    char *end;

    if (colon == NULL || colon[1] == '\0')
        return -1;

    errno = 0;
    long year = strtol(colon + 1, &end, 10);

    if (errno == ERANGE || *end != '\0')
        return -1;

    *out_year = (int)year;
    return 0;
}

int modern_make_slug(const char *name, char *out, size_t out_size) {
    size_t i;

    /* TODO(student): safe slug conversion
       - same transformation as legacy_make_slug
       - must not write past out_size
       - always NUL-terminate on success
       - return 0 on success, -1 if output buffer too small
    */
    if (out_size == 0) {
        return -1;
    }

    for (i = 0; name[i] != '\0' && i + 1 < out_size; i++) {
        if (name[i] == ' ') {
		out[i] = '_' ;
	}else{
		out[i] = tolower(name[i]);
	}
    }

    if (name[i] != '\0') {
        return -1;
    }

    out[i] = '\0';
    return 0;
}
