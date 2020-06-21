#!/bin/sh

rm -f git.log
git log > git.log
git add -f ./git.log
git commit -m "Added the git log to your lab00 folder"
git push origin master
