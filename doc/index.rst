Introduction
========================================================================================================================

|ProjectFriendlyName|, version |ProjectVersion|, is an example integration and playground of a client and server
architecture using the `COVESA / GENIVI Common API C++ Framework <https://covesa.github.io/capicxx-core-tools/>`_,
covering both runtimes and code generators and also supporting both
`D-Bus <https://www.freedesktop.org/wiki/Software/dbus/>`_ and `SOME/IP <https://some-ip.com/>`_ bindings.

For convenience, a list of relevant repositories and resources from the relevant organizations is listed below.
These resources are the latest at the time of writing, and the ones used for the development of this project.

- `COVESA / GENIVI Common API C++ Core Tools v3.2.15 repository <https://github.com/COVESA/capicxx-core-tools/tree/3.2.15>`_

  - `Common API C++ Core Tools v3.2.15 Specification <_static/CommonAPICppSpecification.pdf>`_
  - `Common API C++ Core Tools v3.2.15 User Guide <_static/CommonAPICppUserGuide.pdf>`_
  - `Common API C++ Core Tools v3.2.15 Deployment Specification <_static/CommonAPI-4_deployment_spec.fdepl>`_

- `COVESA / GENIVI Common API C++ D-Bus Tools v3.2.15 repository <https://github.com/COVESA/capicxx-dbus-tools/tree/3.2.15>`_

  - `Common API C++ D-Bus Tools v3.2.15 User Guide <_static/CommonAPIDBusCppUserGuide.pdf>`_
  - `Common API C++ D-Bus Tools v3.2.15 Deployment Specification <_static/CommonAPI-4-DBus_deployment_spec.fdepl>`_

- `COVESA / GENIVI Common API C++ SOME/IP Tools v3.2.15 repository <https://github.com/COVESA/capicxx-someip-tools/tree/3.2.15>`_

  - `Common API C++ SOME/IP Tools v3.2.15 User Guide <_static/CommonAPISomeIPCppUserGuide.pdf>`_
  - `Common API C++ SOME/IP Tools v3.2.15 Deployment Specification <_static/CommonAPI-4-SOMEIP_deployment_spec.fdepl>`_

- `COVESA / GENIVI vSomeIP v3.5.3 repository <https://github.com/COVESA/vsomeip/tree/3.5.3>`_

  - `vSomeIP v3.5.3 User Guide <_static/vsomeipUserGuide.html>`_

- `COVESA / GENIVI Common API C++ Core Runtime v3.2.4 repository <https://github.com/COVESA/capicxx-core-runtime/tree/3.2.4>`_
- `COVESA / GENIVI Common API C++ D-Bus Runtime v3.2.3-r1 repository <https://github.com/COVESA/capicxx-dbus-runtime/tree/3.2.3-r1>`_
- `COVESA / GENIVI Common API C++ SOME/IP Runtime v3.2.4 repository <https://github.com/COVESA/capicxx-someip-runtime/tree/3.2.4>`_
- `Franca User Guide v0.12.0.1 <_static/FrancaUserGuide-0.12.0.1.pdf>`_

It is recommended to first refer to the :any:`Application <::App>` to understand the client/server architecture,
followed by the :any:`Common API C++ Abstraction <Utils::Capi>` to understand the Common API C++ framework integration.
The :any:`Test Suites <Tests::Suites>` provide some practice examples and a playground for experimentation and testing
of the different features of the Common API C++ framework.

The source code for |ProjectFriendlyName| is hosted at `Github <https://github.com/dmg0345/commonapi_cpp_examples>`_ and
related *Docker* images for development containers are located at `DockerHub <https://hub.docker.com/r/dmg00345/commonapi_cpp_examples>`_.
`Test Results HTML Report <_static/_test_results/test_report.html>`_ and
`Code Coverage HTML report <_static/_test_coverage/index.html>`_ are also available.

.. note::

    This is the documentation for |ProjectFriendlyName|, version |ProjectVersion|, refer to
    :doc:`utils/versioning` for more details regarding the release.

.. important::

    This project is an open source project built from publicly available repositories and documentation and not
    affiliated with *COVESA / GENIVI*.

    This project is an example integration of the *Common API C++ Framework* based on previous experience and
    interpretation of the author of that documentation.

License
-----------------------------------------------------------------------------------------------------------------------

.. literalinclude:: ../LICENSE

.. toctree::
    :caption: Main
    :titlesonly:
    :hidden:

    self
    app/index
    utils/index
    tests/index
