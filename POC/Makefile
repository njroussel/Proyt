.PHONY: help format lint mypy all

help:
	@echo "format - format Python code with isort/Black"
	@echo "lint - check style with pylint"
	@echo "mypy - run the static type checker"
	@echo "all - run everything"

format:
	isort src
	black --line-length 100 src

lint:
	mkdir -p reports
	pylint src

mypy:
	mypy src

all:
	format lint mypy
