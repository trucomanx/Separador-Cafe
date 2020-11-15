#!/bin/bash

pdflatex  article_0.tex
biber article_0
pdflatex  article_0.tex
pdflatex  article_0.tex

./Clean.sh
