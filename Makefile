# Copyright 2019 Matthew Calligaro
# Makefile: A makefile for linting and formatting all code in the repository

lint:
	cpplint */*.*pp

format:
	clang-format --style=file -i */*.*pp
