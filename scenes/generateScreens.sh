#!/bin/bash

mkdir -p scenes

find scenes -name '*.yaax' -type f -exec ./raytracer --scene-path {} --output-path {} \;

mkdir -p screenshots
mv ./scenes/**/*.ppm screenshots
mv ./scenes/*.ppm screenshots
