 #!/bin/bash
set -e

echo "The repository that is currently running is: $GITHUB_REPOSITORY"

COMMIT_MESSAGE=$(git log -1 HEAD --pretty=format:%s)  #each time takes the most recent commit after push

# echo $COMMIT_MESSAGE
echo
if echo "$COMMIT_MESSAGE" | grep -i -q -e "jenkins" -e "jenk" -e "kins";
then
    echo "The jenkins job should be triggered"   #here will be added the jenkins job-pipeline if the word jenkins is found
else
    echo "No job should run-trigerred"
fi
