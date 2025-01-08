CommonAPI C++ Examples
========================================================================================================================

**Common API C++ Examples** is an example integration of the `COVESA / GENIVI CommonAPI C++ framework <https://covesa.github.io/capicxx-core-tools/>`_,
along with detailed examples and documentation.

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

1. Create a *release* branch from ``develop`` branch named ``release/X.Y.Z``.
2. Update version in *conf.py* file and in *versioning.cmake* file commit this and other changes to ``release/X.Y.Z``.
3. Afterwards, on ``release/X.Y.Z``, run *cmake* with ``-DCFG_TAG:BOOL=ON`` to tag all files and commit changes.
4. Create a pull request from ``release/X.Y.Z`` to ``master``, with title *Release X.Y.Z*, and merge it.
5. When merged in ``master`` create release and tag from *Github* from merged commit, review production workflow passes.
6. On ``release/X.Y.Z``, run *cmake* with ``-DCFG_TAG:BOOL=RESTORE`` to untag all files and commit changes.
7. Create pull request from ``release/X.Y.Z`` to ``develop``, with the title *Release X.Y.Z*, and merge it.
8. Do not delete the branch ``release/X.Y.Z``.
