#!/usr/bin/env bash

# Alexis Megas.

VERSION=$1

if [ -z "$VERSION" ]
then
    echo "Please specify the version: $0 <VERSION>."
    exit 1
fi

for file in Distributions/*/control
do
    sed -i "s/Version: .*/Version: $VERSION/" $file
done

for file in Distributions/build*
do
    sed -i \
    "s/Dooble-[[:digit:]]\+\.[[:digit:]]\+\.[[:digit:]]\+/Dooble-$VERSION/" \
    $file
done

FILE="Data/Info.plist"

sed -i 's/[0-9]\+\.[0-9]\+.[0-9]\+/'"$VERSION"'/' $FILE

FILE="Source/dooble_version.h"

sed -i \
    's/\(DOOBLE_VERSION_STRING "\)[0-9]\+\(\.[0-9]\+\)*"/\1'"$VERSION"'"/' \
    $FILE
sed -i \
's/\(DOOBLE_VERSION_STRING_LTS "\)[0-9]\+\(\.[0-9]\+\)*"/\1'"$VERSION"'"/' \
$FILE
echo "Please modify ReleaseNotes.html."
