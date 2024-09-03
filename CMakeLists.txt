cmake_minimum_required(VERSION 3.10)

# Define the project name
project(MyProject C)

# Set C standard
set(CMAKE_C_STANDARD 11)

# Add an executable target
add_executable(fifo
    fifo.c
    models/models.c
    parse/parse.c
    plot/process_plot.c
)

# Specify include directories
target_include_directories(fifo PRIVATE
    models
    parse
    plot
)
