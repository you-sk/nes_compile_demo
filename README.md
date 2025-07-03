# NES Compile Demo

Dockerを使用して任天堂ファミリーコンピュータ(NES)のROMイメージをコンパイルするデモプロジェクトです。

## 概要

このプロジェクトは、C言語で書かれたNESゲームをcc65コンパイラを使用してROMイメージ(.nesファイル)にコンパイルする開発環境を提供します。

## 機能

- Dockerベースの開発環境
- C言語でのNESゲーム開発
- 「HELLO WORLD」を表示するサンプルプログラム
- 自動ビルドシステム(Makefile)

## 必要な環境

- Docker

## 使用方法

### 1. 開発環境のビルド

```bash
docker build -t my-nes-dev .
```

### 2. ROMイメージのコンパイル

```bash
docker run --rm -v $(pwd):/app my-nes-dev make
```

### 3. クリーンアップ（再コンパイル前に実行）

```bash
docker run --rm -v $(pwd):/app my-nes-dev make clean
```

## プロジェクト構成

```
.
├── Dockerfile          # 開発環境用Dockerファイル
├── Makefile            # ビルドシステム
├── main.c              # メインプログラム（C言語）
├── nes.h               # NES用ヘッダファイル
├── nes.cfg             # リンカ設定ファイル
├── main.nes            # 生成されるROMイメージ（出力）
└── README.md           # このファイル
```

## サンプルプログラム

含まれているサンプルプログラムは、画面に「HELLO WORLD」を表示するシンプルなNESゲームです。

### 主な機能
- PPU（Picture Processing Unit）の初期化
- パレットデータの設定
- 画面への文字列描画
- 基本的なNESプログラムの構造

## 技術詳細

### 使用ツール
- **cc65**: 6502系プロセッサ用Cコンパイラ
- **Docker**: 開発環境の標準化
- **make**: ビルドシステム

### メモリマップ
- PRG ROM: $8000-$FFFF (32KB)
- CHR ROM: $0000-$1FFF (8KB)
- RAM: $0200-$07FF (1.5KB)
- Zero Page: $0000-$00FF (256B)

## 出力ファイル

コンパイルに成功すると、以下のファイルが生成されます：
- `main.nes`: 実行可能なNESROMイメージ
- `main.o`: オブジェクトファイル
- `main.map`: メモリマップファイル

## ライセンス

このプロジェクトはMITライセンスの下で公開されています。

使用しているcc65コンパイラは、zlib/libpngライセンスに類似したライセンスの下で配布されています。詳細はcc65の公式ドキュメントを参照してください。

## 参考資料

- [cc65 Official Website](https://cc65.github.io/)
- [cc65 GitHub Repository](https://github.com/cc65/cc65)
- [NES Dev Wiki](https://www.nesdev.org/)

## 開発履歴

- 2025/06/26: 初回環境構築完了
- リンカ設定ファイル(nes.cfg)の修正によりコンパイル成功