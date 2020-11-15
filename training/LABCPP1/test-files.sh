#!/bin/bash

strings=(
    "/home/fernando/Dropbox/Cafe-Arbusto/WorkGroup1/data/imagen1.bmp"
    "/home/fernando/Dropbox/Cafe-Arbusto/WorkGroup1/data/imagen2.bmp"
    "/home/fernando/Dropbox/Cafe-Arbusto/WorkGroup1/data/imagen3.bmp"
    "/home/fernando/Dropbox/Cafe-Arbusto/WorkGroup1/data/imagen4.bmp"
)

output_dir="/home/fernando/Downloads/output"

for i in "${strings[@]}"; do
    echo ./make-cromatic "--input-file" "$i" "--output-dir" "${output_dir}"
    ./make-cromatic "--input-file" "$i" "--output-dir" "${output_dir}"
done

