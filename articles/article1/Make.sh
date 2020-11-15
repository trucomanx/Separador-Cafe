#!/bin/bash

pdflatex  article_1.tex
biber article_1
pdflatex  article_1.tex
pdflatex  article_1.tex

./Clean.sh
