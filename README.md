
# MALWARE-SAMPLES DATASET
> **Disclaimer:** Este repositorio contiene **muestras reales de malware** en formato ejecutable (`.exe`) y artefactos derivados de su ejecución en la sandbox CAPEv2 (informes JSON/HTML, capturas de pantalla, archivos dropeados). **NO** ejecute ninguno de los binarios en máquinas en producción ni en equipos no aislados. Este README explica la estructura del dataset, metadatos, uso seguro y requisitos legales/éticos. Este dataset ha sido creado con fines meramente investigativos, los creadores **NO** nos hacemos responsables del uso dado por terceros.

---


## Contenido

1. [Descripción](#descripción)  
2. [Origen y atribución](#origen-y-atribución)  
3. [Estructura del dataset](#estructura-del-dataset)  
4. [Descripción de archivos y formato](#descripción-de-archivos-y-formato)  
5. [Configuración CAPEv2 sandbox](#configuración-capev2-sandbox)
6. [Contacto](#contacto)
---

## Descripción

Este dataset agrupa únicamente las **muestras `.exe`** extraídas de tres repositorios públicos y sus resultados de ejecución en la sandbox **CAPEv2**. Para cada muestra incluye:

- El binario (`.exe`)  
- `report.json` generado por CAPEv2
- `report.html` (versión HTML del informe CAPEv2)  
- Capturas de pantalla tomadas por CAPE durante el análisis  
- Archivos dropeados durante la ejecución dinámica (si los hubo)
---

## Origen y atribución

Las muestras originales proceden de los repositorios públicos (solo se incluyeron las muestras `.exe`):

- `ytisf/theZoo` — https://github.com/ytisf/theZoo  
- `Pyran1/MalwareDatabase` — https://github.com/Pyran1/MalwareDatabase  
- `Da2dalus/The-MALWARE-Repo` — https://github.com/Da2dalus/The-MALWARE-Repo
---


## Estructura del dataset

Estructura de alto nivel (raíz del repositorio):
```
dataset/
├── JSONs/ 
│    └── <md5>.json # report.json (renombrado por md5)
├── reports/
│    └── <md5>.html # report.html (renombrado por md5)
├── screenshots/
│    └── <md5>/     # md5 de la muestra de malware
│          ├── 0001.png
│          ├── 0002.png
│          └── ...
├── binaries/
│    └── <md5>.exe  # muestra de malware ejecutable
└── dropped_files/
     └── <md5>/     # md5 de la muestra de malware
           ├── fileA
           ├── fileB
           └── ...
```
---

## Descripción de archivos y formato

- **`binaries/<md5>.exe`**  
  Copia del ejecutable original. **No ejecutar** en equipos no controlados.

- **`JSONs/<md5>.json`**  
  Salida JSON del análisis CAPEv2: metadata, procesos, archivos dropeados, actividad de red, firmas, etc.

- **`Reports/<md5>.html`**  
  Versión HTML del informe generada por CAPEv2.

- **`screenshots/<md5>/*.png`**  
  Capturas de pantalla tomadas durante la ejecución dinámica.

- **`dropped_files/<md5>/*`**  
  Archivos que el malware dejó en disco durante su ejecución dentro de la sandbox.

---


## Configuración CAPEv2 sandbox

> **Resumen:** Para analizar muestras con capacidades evasivas se realizaron ajustes en las configuraciones de la sandbox CAPEv2 utilizada durante la generación de este dataset. Con el fin de permitir la replicación del experimento, en el repositorio se incluyen los archivos de configuración utilizados (la carpeta `conf/` de CAPEv2) y el XML de máquina virtual KVM personalizada.

### ¿Qué contiene esta sección?

Se publicará la siguiente estructura dentro del repositorio:
```

CAPEv2 Configuration/
├── XML KVM/
│     └── xml-custom-machine.xml # XML para configurar la VM en KVM
└── conf/
      └── ... # Archivos y carpetas de configuración de CAPEv2
```

- **`XML KVM/`**  
  Contiene el descriptor XML de la máquina virtual (nombres indicativos: `xml-custom-machine.xml`). Este XML refleja la VM usada en los análisis (vCPU, memoria, dispositivos virtuales, discos, NICs simuladas, etc.) para que otros puedan importar/definir una VM equivalente en su entorno de virtualización.

- **`conf/`**  
  Copia de la carpeta `conf` utilizada por CAPEv2 en el experimento. Incluye los ficheros de configuración relevantes de CAPEv2 (rutas, timeouts, módulos habilitados, integración con el backend de análisis, parámetros de captura de red, etc.). **Nota:** cualquier dato sensible (credenciales, claves privadas) ha sido eliminado.
---
## Contacto
### Raúl Bayón Martínez

Phd student/Personal investigador de la universidad de León

e-mail: rbaym@unileon.es

---

### Adrián Prieto

Técnico en investigación de la universidad de León

e-mail: aprig@unileon.es
