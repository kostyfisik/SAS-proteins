#!/bin/bash
#git remote add upstream https://github.com/Yarokha/SAS-proteins
git fetch upstream
git checkout master
git merge upstream/master
