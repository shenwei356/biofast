#include <zlib.h>
#include <stdio.h>
#include "kseq.h"
KSEQ_INIT(gzFile, gzread)

int main(int argc, char *argv[])
{
	gzFile fp;
	kseq_t *seq;
	int n = 0, slen = 0, qlen = 0;
	if (argc == 1) {
		printf("Usage: fqcnt <in.fq.gz>");
		return 0;
	}
	fp = gzopen(argv[1], "r");
	seq = kseq_init(fp);
	while (kseq_read(seq) >= 0)
		++n, slen += seq->seq.l, qlen += seq->qual.l;
	printf("%d\t%d\t%d\n", n, slen, qlen);
	kseq_destroy(seq);
	gzclose(fp);
	return 0;
}
