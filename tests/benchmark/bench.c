/*
 * SPDX-License-Identifier: GPL-2.0-or-later
 *
 * Copyright 2010 Douglas Santos <douglas.santos@polymtl.ca>
 *
 * LTTng Userspace Tracer (UST) - benchmark tool
 */

#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <sched.h>
#include <time.h>

#ifdef TRACING
#define TRACEPOINT_DEFINE
#include "ust_tests_benchmark.h"
#endif

static int nr_cpus;
static unsigned long nr_events;

void do_stuff(void)
{
	int v;
	FILE *file;

	v = 1;

	file = fopen("/dev/null", "a");
	fprintf(file, "%d", v);
	fclose(file);
	time(NULL);

#ifdef TRACING
	tracepoint(ust_tests_benchmark, tpbench, v);
#endif

}


void *function(void *arg)
{
	unsigned long i;

	for(i = 0; i < nr_events; i++) {
		do_stuff();
	}
	return NULL;
}

void usage(char **argv) {
	printf("Usage: %s nr_cpus nr_events\n", argv[0]);
}


int main(int argc, char **argv)
{
	void *retval;
	int i;

	if (argc < 3) {
		usage(argv);
		exit(1);
	}

	nr_cpus = atoi(argv[1]);
	printf("using %d processor(s)\n", nr_cpus);

	nr_events = atol(argv[2]);
	printf("using %ld events per cpu\n", nr_events);

	pthread_t thread[nr_cpus];
	for (i = 0; i < nr_cpus; i++) {
		if (pthread_create(&thread[i], NULL, function, NULL)) {
			fprintf(stderr, "thread create %d failed\n", i);
			exit(1);
		}
	}

	for (i = 0; i < nr_cpus; i++) {
		if (pthread_join(thread[i], &retval)) {
			fprintf(stderr, "thread join %d failed\n", i);
			exit(1);
		}
	}
	return 0;
}
