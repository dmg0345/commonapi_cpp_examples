CommonAPI C++ Examples
========================================================================================================================

**Common API C++ Examples** is a collection of examples for the `COVESA / GENIVI CommonAPI C++ framework <https://covesa.github.io/capicxx-core-tools/>`_.

Refer to the documentation `here <https://dmg0345-commonapi-cpp-examples.netlify.app>`_ for details.

Build and Development
------------------------------------------------------------------------------------------------------------------------

Clone the repository as:

.. code-block:: powershell

    git clone https://github.com/dmg0345/commonapi_cpp_examples

Example commands to build the source code and run the tests are provided below:

.. code-block:: powershell

    cmake -C "./other/cmake/preload/release.cmake" -S . -B "./.cmake_build"
    cmake --build "./.cmake_build" -j --target all
    ctest --test-dir "./.cmake_build"

Find the base Docker image for the development container at `DockerHub <https://hub.docker.com/r/dmg00345/commonapi_cpp_examples>`_.
To develop using `devcontainers` and `Visual Studio Code`:

.. code-block:: powershell

    docker pull dmg00345/commonapi_cpp_examples:latest
    ./manage.ps1 run

Create a release
------------------------------------------------------------------------------------------------------------------------

To generate a release follow the steps below:

1. Create a ``release`` branch from ``develop`` branch named ``release/X.Y.Z``.
2. Update version in *conf.py* file and in *version.cmake* file, commit change to ``release/X.Y.Z`` branch.
3. Create branch called ``release/X.Y.Z_tag`` from ``release/X.Y.Z``
4. On branch ``release/X.Y.Z_tag``, run *cmake* with ``-DCFG_TAG:BOOL=ON`` to tag all files, and commit the changes.
5. Create pull request from ``release/X.Y.Z_tag`` branch to ``master`` branch, with the title *Release X.Y.Z*.
6. Create pull request from ``release/X.Y.Z`` branch to ``develop`` branch, with the title *Release X.Y.Z*.
7. When merged in ``master`` create release and tag from *Github* from merged commit, review production workflow passes.
8. Delete the ``release/X.Y.Z_tag`` branch, keep the ``release/X.Y.Z`` branch, which holds the commit hash tagged.
