 #!/bin/bash
set -e

    echo "The repository that is currently running is: $GITHUB_REPO"

if echo "$*" | grep -i -q -e "jenkins" -e "jenk" -e "kins";
then
    echo "Found keyword"
else
    echo "Nothing to process Marinos"
fi
