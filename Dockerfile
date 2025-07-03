# 公式の安定したDebianイメージをベースにする
FROM debian:bullseye-slim

# 必要なツール（make, cc65スイート）を公式リポジトリからインストール
RUN apt-get update && \
    apt-get install -y --no-install-recommends \
    make \
    cc65 \
    && rm -rf /var/lib/apt/lists/*

# 作業ディレクトリを設定
WORKDIR /app