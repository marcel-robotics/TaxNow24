SHELL := bash
.ONESHELL:
.SHELLFLAGS := -eu -o pipefail -c
.DELETE_ON_ERROR:
MAKEFLAGS += --warn-undefined-variables
MAKEFLAGS += --no-builtin-rules
.DEFAULT_GOAL := help

define PRINT_HELP_PYSCRIPT
import re, sys

for line in sys.stdin:
	match = re.match(r'^([a-zA-Z_-]+):.*?## (.*)$$', line)
	if match:
		target, help = match.groups()
		print("%-20s %s" % (target, help))
endef
export PRINT_HELP_PYSCRIPT

SRC_PATH := "./jobs"

.PHONY: help
help: ## Shows help for targets with help text
	@python -c "$$PRINT_HELP_PYSCRIPT" < $(MAKEFILE_LIST)

.PHONY: install
install: ## Installs all dependencies
	poetry install

.PHONY: requirements.txt
requirements.txt: ## Creates requirements.txt file
	poetry export -f requirements.txt --output requirements.txt

.PHONY: lint
lint: ## Checks code formatting and style
	poetry run pylint $(SRC_PATH)

.PHONY: type-check
type-check: ## Checks types
	poetry run mypy --ignore-missing-imports --strict --allow-subclassing-any --follow-imports=skip \
		$(SRC_PATH)

.PHONY: auto-format
auto-format: ## Automatically formats the code
	poetry run black $(SRC_PATH) ./tests

.PHONY: unit-test
unit-test: ## Runs all unit tests
	poetry run pytest -v -s ./tests/unit

.PHONY: integration-test
integration-test: ## Runs all integration tests
	poetry run pytest -v -s ./tests/integration

.PHONY: test
test: unit-test integration-test ## Runs all tests

.PHONY: check
check: auto-format lint type-check test ## Runs all code checks and tests

.PHONY: deploy
deploy: ## Deploys jobs into datalake
	poetry build
	cp ./dist/jobs-*.whl ../datalake/jobs
	cp ./jobs/run_*.py ../datalake/jobs

.PHONY: run
run: ## Run a specific job locally
	poetry run spark-submit \
        --master local \
        --packages org.apache.spark:spark-avro_2.12:3.2.1 \
        --py-files dist/jobs-*.whl \
        $(JOB_RUN_FILE) \
        $(INPUT_FILE) \
        $(OUTPUT_FILE)

.PHONY: check-setup
check-setup: ## Check if the setup with all dependencies is working as needed
	poetry run pytest -v -s ./tests/integration/test_event_listing.py
