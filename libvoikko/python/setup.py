import os
import sys
import subprocess
from setuptools import setup

if sys.version_info[:2] < (3, 3):
    raise RuntimeError("Python version >= 3.3 required.")

setup(
    name="libvoikko",
    author="Voikko",
    description="Lemmatize words",
    version="2.3.0",
    packages=['libvoikko'],
    url='https://github.com/voikko/corevoikko',
    install_requires=[],
    package_data={},
    keywords="voikko libvoikko"
)
