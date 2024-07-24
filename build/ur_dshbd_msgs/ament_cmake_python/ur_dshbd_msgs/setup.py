from setuptools import find_packages
from setuptools import setup

setup(
    name='ur_dshbd_msgs',
    version='0.0.0',
    packages=find_packages(
        include=('ur_dshbd_msgs', 'ur_dshbd_msgs.*')),
)
