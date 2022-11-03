 #!/bin/bash
set -e

echo "The repository that is currently running is: $GITHUB_REPOSITORY"

COMMIT_MESSAGE=$(git log -1 HEAD --pretty=format:%s)

if "$COMMIT_MESSAGE" | grep -i -q -e "jenkins" -e "jenk" -e "kins";
then
    echo "Found keyword"
else
    echo "Nothing to process Marinos"
fi
