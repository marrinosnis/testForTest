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

    if echo "$COMMIT_MESSAGE" | grep -i -q -e "jenkins" -e "jenk" -e "kins" #TODO: should change that, with the shell script testing [[ .. ]]
    then
        echo "The jenkins job should be triggered"   #return YES so the Jenkins pipeline can start the trigger
        exit 0
    else
        echo "No job should run-trigerred"     
        #exit 1  #  exit with 1, so NONE Jenkins pipeline will start
    fi

fi
