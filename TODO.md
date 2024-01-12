This TODO list is automatically generated from the cookiecutter-cpp-project template.
The following tasks need to be done to get a fully working project:

* Set up a remote repository. You can e.g. create a project in GitHub or GitLab and run
  the following commands in your locally generated project folder: `git remote add origin <Remote-URL>`
  For a seamless integration, the name of the project should also be `example-cookiecutter-cpp-project`.
* Make sure that the following software is installed on your computer:
  * A C++-20-compliant C++ compiler
  * CMake `>= 3.9`
  * Adapt your list of external dependencies in `CMakeLists.txt` and `example-cookiecutter-cpp-projectConfig.cmake.in`.
    You can e.g.
    * Link your library or applications to your dependency. For this to work, you need
      to see if your dependency exports targets and what their name is. As this is highly
      individual, this cookiecutter could not do this for you.
    * Add more dependencies in analogy to `FAKE_DEPENDENCY`
    * Make dependencies requirements by adding `REQUIRED` to `find_package()`
    * Add version constraints to dependencies by adding `VERSION` to `find_package()`
    * Make a dependency a pure build time dependency by removing it from `example-cookiecutter-cpp-projectConfig.cmake.in`
* Make sure that CI/CD pipelines are enabled in your Gitlab project settings and that
  there is a suitable Runner available. If you are using the cloud-hosted gitlab.com,
  this should already be taken care of.
* Enable the integration of Readthedocs with your Git hoster. In the case of Github, this means
  that you need to login at [Read the Docs](https://readthedocs.org) and click the button
  *Import a Project*.
* Make sure that doxygen is installed on your system, e.g. by doing `sudo apt install doxygen`
  on Debian or Ubuntu.
* Edit the parameters of `setup()` in `setup.py` file to contain the necessary information
  about your project, such as your email adress, PyPI classifiers and a short project description.
* Head to your user settings at `https://pypi.org` and `https://test.pypi.org/` to setup PyPI trusted publishing.
  In order to do so, you have to head to the "Publishing" tab, scroll to the bottom
  and add a "new pending publisher". The relevant information is:
  * PyPI project name: `examplecookiecuttercppproject`
  * Owner: `None`
  * Repository name: `None`
  * Workflow name: `pypi.yml`
  * Environment name: not required