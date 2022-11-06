#!/usr/bin/env bash
set -e

echo "The repository that is currently running is: $GITHUB_REF_NAME"
echo

if [[ $GITHUB_REF_NAME == *_epic ]];
then
    echo "The branch is EPIC"
else
    echo "The brach is about to RUN"
fi

echo
COMMIT_MESSAGE=$(git log -1 HEAD --pretty=format:%s)  #each time takes the most recent commit after push

echo
if echo "$COMMIT_MESSAGE" | grep -i -q -e "jenkins" -e "jenk" -e "kins"; #TODO: should change that, with the shell script testing [[ .. ]]
then
    echo "The jenkins job should be triggered"   #TODO: add here will be added the jenkins job-pipeline if the word jenkins is found
else
    echo "No job should run-trigerred"
fi
