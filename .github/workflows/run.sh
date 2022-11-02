 #!/bin/bash
set -e

if [ -n "$GITHUB_REPOSITORY" ];
then
    GITHUB_REPO=$GITHUB_REPOSITORY
    echo "The repository that is currently running is: $GITHUB_REPO"
else
    echo "No repo at the current time"
fi

if echo "$*" | grep -i -q -e "jenkins" -e "jenk" -e "kins";
then
    echo "Found keyword"
else
    echo "Nothing to process Marinos"
fi
