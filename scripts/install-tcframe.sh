TCFRAME_VERSION="1.6.0"
OUTPUT_PATH="tmp"

echo "Downloading tcframe"
sudo apt install build-essential -y

TCFRAME_ZIP="tcframe_$TCFRAME_VERSION.zip"
DOWNLOAD_PATH="https://github.com/tcframe/tcframe/releases/download/v$TCFRAME_VERSION/$TCFRAME_ZIP"

mkdir -p $OUTPUT_PATH
wget $DOWNLOAD_PATH -O $OUTPUT_PATH/$TCFRAME_ZIP
unzip $OUTPUT_PATH/$TCFRAME_ZIP -d $HOME/tcframe
rm -rfv $OUTPUT_PATH

echo "
export TCFRAME_HOME=$HOME/tcframe
alias tcframe=$HOME/tcframe/scripts/tcframe
" >> $HOME/.bashrc && source $HOME/.bashrc
