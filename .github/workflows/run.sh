#!/bin/bash
set -e

echo "The branch that is currently running is: $GITHUB_REF_NAME"

if [[ $GITHUB_REF_NAME == *_epic ]]; then 
    echo "The branch is EPIC"  # if the the name of branch ends in '_epic' I DO NOT want to triger the jenkins pipeline
    echo "No Jenkins job should be trigger"
else
    echo "The branch is NOT EPIC, and is about to run"
    echo;
    COMMIT_MESSAGE=$(git log -1 HEAD --pretty=format:%s)  #each time takes the most recent commit after push

    #if echo "$COMMIT_MESSAGE" | grep -i -q -e "jenkins" -e "jenk" -e "kins" #TODO: should change that, with the shell script testing [[ .. ]]
    if [[ $COMMIT_MESSAGE =~ "jenkins" ]]   # paizei, alla prepei na balw kai multple words na ta kanei check
    then
        echo "The jenkins job should be triggered"
    else
        echo "NO JOBS WILL BE RUN"
    fi

fi
