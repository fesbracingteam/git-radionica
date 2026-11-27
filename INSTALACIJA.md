# Instalacija C prevoditelja (gcc) i `make`

Za kviz trebaš C prevoditelj i `make`. Nađi svoj sustav i pokreni jednu naredbu.

## macOS

```bash
xcode-select --install
```

Dobiješ `gcc`, `make` i `git`. Na macOS-u je `gcc` zapravo `clang`, što je za radionicu u redu.

## Linux

| Distribucija | Naredba |
|---|---|
| Ubuntu, Debian, Linux Mint, Pop!_OS | `sudo apt update && sudo apt install -y build-essential` |
| Fedora | `sudo dnf install -y gcc make` |
| Arch, Manjaro | `sudo pacman -S --needed gcc make` |
| openSUSE | `sudo zypper install -y gcc make` |

## Windows

### WSL s Ubuntuom (preporučeno)

Skripta iz zadatka 2b i `make check` trebaju Unix ljusku, a WSL je ima. U PowerShellu pokrenutom kao administrator:

```powershell
wsl --install
```

Ponovno pokreni računalo i otvori aplikaciju **Ubuntu**. U njoj pokreni:

```bash
sudo apt update && sudo apt install -y build-essential
```

Sve naredbe na radionici upisuješ u Ubuntu terminal.

### MSYS2 (ako WSL ne radi)

U PowerShellu:

```powershell
winget install -e --id MSYS2.MSYS2
```

Otvori **MSYS2 UCRT64** iz Start izbornika i u njemu pokreni:

```bash
pacman -S --needed mingw-w64-ucrt-x86_64-gcc make
```

Na radionici radiš u terminalu MSYS2 UCRT64.

## Provjera

```bash
gcc --version && make --version
```

Ako obje naredbe ispišu verziju, sve je spremno. Zatim u kloniranom repozitoriju pokreni `make check`.
