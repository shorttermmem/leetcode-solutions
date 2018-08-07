#========================================================
# Host OS
#========================================================
# container UUID
BUILDID="build-$RANDOM"
# image tag
INSTANCE="travisci/ci-garnet:packer-1512502276-986baf0"

# Start a container from an image on docker public registry
docker run --name $BUILDID -dit $INSTANCE /sbin/init

# Run cmd in a running container
docker exec -it $BUILDID bash -l

#========================================================
# Inside container environment
#========================================================
# switch admin account
su - travis

# clone this project
git clone https://github.com/shorttermmem/leetcode-solutions.git

