# jobs
A collection of _Python_ (spark) jobs to transform data that are build with poetry.

## Prerequisites
* Python >= 3.10, you can use for example [pyenv](https://github.com/pyenv/pyenv#installation) to manage that
* [Poetry](https://python-poetry.org/docs/#installation)

## Installing dependencies
```bash
make install
```

## Tests and checks
To run all tests and checks:
```bash
make check
```

To run all tests (unit and integration):
```bash
make test
```

### unit-tests
To just run unit-tests:
```bash
make unit-test
```

### integration-tests
To just run integration-tests:
```bash
make integration-test
```

### Auto-formatting
```bash
make auto-format
```

### Linting
```bash
make lint
```

### Check types
```bash
make type-check
```

## Run locally
To run locally:
```bash
JOB_RUN_FILE="jobs/run_<job_name>.py" INPUT_FILE="<input_file>" OUTPUT_FILE="<output_file>" make run
```

where
```
<job_name> is the name of the job you want to run

<input_file> is the input file for the job

<output_file> is the output file for the job
```