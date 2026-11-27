# Instalacija alata

Za radionicu trebaš C prevoditelj (`gcc`), `make`, `git` i GitHub CLI (`gh`). Nađi svoj sustav i pokreni naredbe.

## macOS

```bash
xcode-select --install && brew install gh
```

Dobiješ `gcc`, `make`, `git` i `gh`. Na macOS-u je `gcc` zapravo `clang`, što je za radionicu u redu. Ako nemaš Homebrew, uputa je na https://brew.sh

## Linux

| Distribucija | Naredba |
|---|---|
| Ubuntu, Debian, Linux Mint, Pop!_OS | `sudo apt update && sudo apt install -y build-essential git gh` |
| Fedora | `sudo dnf install -y gcc make git gh` |
| Arch, Manjaro | `sudo pacman -S --needed gcc make git github-cli` |
| openSUSE | `sudo zypper install -y gcc make git gh` |

Ako tvoj sustav ne nađe paket `gh`, uputa je na https://github.com/cli/cli/blob/trunk/docs/install_linux.md

## Windows

Dvije mogućnosti. **WSL je jednostavniji**: sve radi kao na Linuxu i ništa ne trebaš dodavati u PATH.

### Mogućnost 1: WSL s Ubuntuom (preporučeno)

1. U PowerShellu pokrenutom kao administrator:
   ```powershell
   wsl --install
   ```
2. Ponovno pokreni računalo i otvori aplikaciju **Ubuntu** (prvi put traži korisničko ime i lozinku za Linux).
3. U Ubuntu terminalu:
   ```bash
   sudo apt update && sudo apt install -y build-essential git gh
   ```

Sve naredbe na radionici upisuješ u Ubuntu terminal. PATH se ne mijenja.

### Mogućnost 2: Windows bez WSL-a (MSYS2 + Git for Windows)

0. **Provjeri imaš li `winget`.** U PowerShellu:
   ```powershell
   winget --version
   ```
   Ako ispiše verziju, idi na korak 1. Ako piše da `winget` nije prepoznat, instaliraj ga na jedan od ovih načina pa otvori novi PowerShell i ponovno provjeri `winget --version`:
   - **Ponovno registriraj** (winget je na Windowsima 10 i 11 obično već tu, samo nije aktiviran):
     ```powershell
     Add-AppxPackage -RegisterByFamilyName -MainPackage Microsoft.DesktopAppInstaller_8wekyb3d8bbwe
     ```
   - **Ako to ne pomogne** — u PowerShellu pokrenutom kao administrator:
     ```powershell
     Install-PackageProvider -Name NuGet -Force; Install-Module -Name Microsoft.WinGet.Client -Force -Repository PSGallery; Repair-WinGetPackageManager -AllUsers
     ```
   - **Ili preko Microsoft Storea:** otvori Microsoft Store, potraži **App Installer** i klikni **Instaliraj** (ili **Ažuriraj**).
1. U PowerShellu instaliraj MSYS2, Git i GitHub CLI:
   ```powershell
   winget install -e --id MSYS2.MSYS2; winget install -e --id Git.Git; winget install -e --id GitHub.cli
   ```
   Git i `gh` se sami dodaju u PATH.
2. Iz Start izbornika otvori **MSYS2 UCRT64** i instaliraj `gcc` i `make`:
   ```bash
   pacman -S --needed --noconfirm mingw-w64-ucrt-x86_64-gcc make
   ```
3. **Dodaj `gcc` i `make` u PATH.** MSYS2 ih stavlja u dvije mape koje Windows ne zna sam pronaći:
   - `C:\msys64\ucrt64\bin` — ovdje je `gcc`
   - `C:\msys64\usr\bin` — ovdje su `make` i `sh`

   **Jednom naredbom** (PowerShell, bez administratora, mijenja samo PATH tvog korisnika):
   ```powershell
   [Environment]::SetEnvironmentVariable("Path", [Environment]::GetEnvironmentVariable("Path", "User") + ";C:\msys64\ucrt64\bin;C:\msys64\usr\bin", "User")
   ```

   **Ili ručno:**
   1. Pritisni tipku Windows, upiši „varijable okruženja” i otvori **Uredi varijable okruženja za svoj račun**.
   2. Pod „Korisničke varijable” odaberi **Path** i klikni **Uredi**.
   3. Klikni **Novo** i upiši `C:\msys64\ucrt64\bin`, pa opet **Novo** i upiši `C:\msys64\usr\bin`.
   4. Klikni **U redu** u oba prozora.

   Ako si MSYS2 instalirao u drugu mapu, umjesto `C:\msys64` upiši tu mapu.
4. **Zatvori sve terminale i otvori novi** — PATH se učitava samo kad se terminal pokrene.
5. Na radionici radi u **Git Bashu** (dolazi s Gitom): ondje rade `git`, `gh`, `gcc`, `make` i skripta iz zadatka 2b.

## Provjera

U terminalu u kojem ćeš raditi (macOS/Linux terminal, Ubuntu ili Git Bash):

```bash
gcc --version && cc --version && make --version && git --version && gh --version
```

Ako svih pet naredbi ispiše verziju, sve je spremno. Zatim u kloniranom repozitoriju pokreni `make check`.

Ako na Windowsu piše `command not found`: provjeri mape u PATH-u (korak 3) i otvori novi terminal (korak 4). Ako radi `gcc`, a ne radi `cc`, umjesto `make check` pokreni `make CC=gcc check`.
