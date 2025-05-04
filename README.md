# QueryLang
Compiler Construction Project detailing the use of QueryLang, a flow-based language that enables operations such as SELECT, FILTER, JOIN, and AGGREGATE in a clear and pipeline-friendly syntax.

# How To Run

For Linux:
  1. **Install Dependencies:** Open the terminal and run '**sudo apt update && sudo apt upgrade -y**', then '**sudo apt install flex bison gcc make -y**'
  2. **Clone Repo:** Run '**git clone https://github.com/Daniyal-Sultan/QueryLang/**'
  3. **Build the Project:** Change directory to the project via '**cd QueryLang**', then start building via '**make**'

For Windows:
  1. **Install WSL:** Open Powershell as Administrator and run '**wsl --install**', then reboot the system.
  2. **Install Ubuntu**: When rebooted, go to the Microsoft Store and install Ubuntu.
  3. **Run The Project:** Once Ubuntu is installed, open it in your Terminal and do Steps 1-3 in the Linux procedure.

# How To Test
  1. **Create A Target Python Script:** Create a simple Python query script '**input.ql**'. The sample code is provided below.
  2. **Generate Script:** Use the already-built querylang and run '**./querylang input.ql > output.py**' in your terminal. This will generate the executable output.py
  3. **Run The Executable:** In your terminal, run '**python3 output.py**' to run the executable. (***Ensure the Pandas library is installed***)

