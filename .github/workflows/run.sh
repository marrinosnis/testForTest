 #!/usr/bin/env bash
set -e

echo
echo "The repository that is currently running is: $GITHUB_REPOSITORY"
EPIC_CHECK=${GITHUB_REPOSITORY: -5}
echo "The value of the EPIC_CHECK is" 
echo $EPIC_CHECK

COMMIT_MESSAGE=$(git log -1 HEAD --pretty=format:%s)  #each time takes the most recent commit after push

# echo $COMMIT_MESSAGE
echo
if echo "$COMMIT_MESSAGE" | grep -i -q -e "jenkins" -e "jenk" -e "kins"; #should change that, with the shell script testing [[ .. ]]
then
    echo "The jenkins job should be triggered"   #here will be added the jenkins job-pipeline if the word jenkins is found
else
    echo "No job should run-trigerred"
fi
