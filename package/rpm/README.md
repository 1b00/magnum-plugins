# Install next packages

## for usage
magnum should be installed and others:
```
sudo dnf install DevIL \
                    openal-soft \
                    libjpeg-turbo \
                    libpng \
                    assimp \
                    freetype \
                    faad2-libs \
                    OpenEXR-libs
```

```
sudo zypper install libIL1 \
                    openal-soft \
                    libjpeg62 \
                    libpng \
                    assimp-devel \
                    freetype \
                    faad2 \
                    openexr
```

## for build and devel package
magnum-devel should be installed and others:
```
sudo dnf install git gcc-c++ cmake make rpmdevtools \
                    DevIL-devel \
                    openal-soft-devel \
                    libjpeg-turbo-devel \
                    libpng-devel \
                    assimp-devel \
                    freetype-devel \
                    faad2-devel \
                    OpenEXR-devel
```

```
sudo zypper install git gcc-c++ cmake make rpmdevtools \
                    DevIL-devel \
                    openal-soft-devel \
                    libjpeg62-devel \
                    libpng-devel \
                    assimp-devel \
                    freetype2-devel \
                    libfaad-devel \
                    OpenEXR-devel
```

## on fedora

### for faad2 and faad2-devel add rpmfusion repo

```
sudo dnf install https://download1.rpmfusion.org/free/fedora/rpmfusion-free-release-$(rpm -E %fedora).noarch.rpm
```

## on centos

### for assimp add EPEL repo
```
sudo dnf install --nogpgcheck https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm
```

### for DevIL only install fc29 package
latest fc packages use newer glibc but centos does not
```
sudo dnf install https://archives.fedoraproject.org/pub/archive/fedora/linux/releases/29/Everything/x86_64/os/Packages/d/DevIL-1.7.8-29.fc29.x86_64.rpm
```
### for DevIL-devel install fc29 packages
latest fc packages use newer glibc but centos does not

```
sudo dnf install https://archives.fedoraproject.org/pub/archive/fedora/linux/releases/29/Everything/x86_64/os/Packages/d/DevIL-1.7.8-29.fc29.x86_64.rpm  https://archives.fedoraproject.org/pub/archive/fedora/linux/releases/29/Everything/x86_64/os/Packages/d/DevIL-devel-1.7.8-29.fc29.x86_64.rpm
```
### for faad2 and faad2-devel add rpmfusion repo
```
sudo dnf install --nogpgcheck https://mirrors.rpmfusion.org/free/el/rpmfusion-free-release-8.noarch.rpm
```
### for OpenEXR enable powertools
```
sudo dnf config-manager --enable powertools
```

## on openSUSE Tumbleweed
```
sudo zypper addrepo https://download.opensuse.org/repositories/home:Simmphonie:ham/openSUSE_Tumbleweed/home:Simmphonie:ham.repo
sudo zypper refresh
```

## on openSUSE Leap 15.2
```
sudo zypper addrepo https://download.opensuse.org/repositories/home:Simmphonie:ham/openSUSE_Leap_15.2/home:Simmphonie:ham.repo
sudo zypper refresh
```