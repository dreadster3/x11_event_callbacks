{pkgs ? import <nixpkgs> {}}:
pkgs.mkShell {
	nativeBuildInputs = with pkgs; [
		gcc
		cmake
	];
	buildInputs = with pkgs.buildPackages; [
		xorg.libX11
		xorg.libX11.dev
	];
}

