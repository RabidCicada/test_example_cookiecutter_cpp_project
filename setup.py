from skbuild import setup


setup(
    packages=["examplecookiecuttercppproject"],
    package_dir={"": "python"},
    zip_safe=False,
    cmake_args=[
        "-DBUILD_TESTING=OFF",
        "-DBUILD_DOCS=OFF",
    ],
    cmake_install_dir="python/examplecookiecuttercppproject",
)
