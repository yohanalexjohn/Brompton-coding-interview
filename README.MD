# Thread safe Bitset opertation on input data

## Brief

This is an implementation of a thread-safe class for managing a large bitset (e.g. 256bits) that provides some simple operations to manipulate and query individual bits.

### Notes

For the sake of portability bitset library was not used as its not portable across
different embedded architectures. Bitwise operators were used as this is portable.

Doxygen was used for the documentaion generation. The provided docker file and steps should build and run the application and source code provided dependencies are missing.
Would recommend while running the container to mount the source code. This allows the
user to view the doxygen report externally in the browser once they have been generated.

## Dependencies

- cmake
- make
- doxygen
- g++

## How to run

### Running locally (Assuming all the dependencies are sorted )

1. Clone the repo
2. Build the project

    ```shell
    make all
    ```

3. Run the executable. From the root directory

    ```shell
    ./build/brompton
    ```

### Running the tests

1. Run the google tests for the project through the following command

    ```shell
    make test
    ```

### Generating and running the docs

1. Generate and run the docs locally through the following command

    ```shell
    make docs
    ```

#### Note

The doxygen should automatically be gennerated under the docs/ directory.
The doxygen html report should automatically open up in the designated broswer
of your choice with all the documentation.

### Using the docker image to run

1. Clone the repo
2. Within the root directory where the dockerfile lives. Build the docker image

    ```shell
    # Build the docker image 
    docker build -t brompton:1.0 .  
    ```

3. Once the docker image is built, Run the image

    ```shell
    # Mount the source code to create a shared link with host machine 
    # and the docker container.
    docker run -it --rm -v "Entire path to the <Brompton> repo ":/brompton brompton:1.0
    ```

4. Run the following for each specific task

    ```shell
    # To Build the project
    make all

    # To run the tests
    make test

    # To generate and view the documentation
    # Within the docker container cannot view the 
    # documentation.
    make docs

    # To clean the directory run: make clean
    ```

To view the documentation on the browser once the docs have been generated.
Run the following command

```shell
# Windows run 
start docs/html/index.html

# Linux run same for MacOS 
xdg-open docs/html/index.html
```
