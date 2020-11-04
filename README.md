# Assignment 2

## Q1.

## Team members:
  - Mamatha Guntu
  - Arshia Sali
  
### Contribution: 
  We divided the coding logic for total exits and total processor cycles.

  - Mamatha Guntu 
    - Created VM, configured Virt Manager to create inner vm. 
    - Included the code for calculating the processor cycles in files cpuid.c and vmx.c and stored it in ebx and ecx registers (higher 32 bits and lower 32 bits respectively) . 
    - Tested the code changes from inner vm.
  
  - Arshia Sali 
    - Created VM, configured Virt Manager to create inner vm.
    - Included the code for calculating the total exits in files cpuid.c and vmx.c and stored it in eax register . 
    - Tested the code changes from inner vm.
    
### Output file(Output.pdf) added under root linux folder.    
### Testfile (testfile.c) added under root linux folder.

## Q2.

### Procedure
1. Install VMWARE WORKSTATION 16 PRO
2. Created a VM with Ubuntu 20.04.1-desktop ISO image file
3. Forked the linux repo from https://github.com/torvalds/linux.
4. Cloned the forked repo in the VM.
5. Navigate to the cloned linux folder and run the below commands:
  - sudo bash
  - apt-get install build-essential kernel-package fakeroot libncurses5-dev libssl-dev ccache bison flex libelf-dev
  - uname -a 
  - cp /boot/config-4.15.0-112-generic ./.config (replace with our kernel version)
  - make oldconfig (accept all default values)
  - make && make modules && make install && make modules_install 
  - reboot
6. Verify that you are using the newer kernel after reboot:
 - uname -a
7. Added the code changes in arch/x86/kvm/cpuid.c and arch/x86/kvm/vmx/vmx.c files.
8. Rebuild using  make && make modules && make install && make modules_install.
9. Reboot. To test the code changes we have to create an inner VM.

TESTING
1. To create an inner vm, execute the below command.
 - sudo apt-get install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virt-manager
2. Run the following command to add your user account to the libvirt group:
 - sudo adduser name libvirt
3. Open Virtual Machine Manager and create a new Virtual Machine using connection QEMU/KVM.
4. Created a VM with Ubuntu 20.04.1-desktop ISO image file.
5. Create a test file to test your kernel code changes.
6. Compile and run the testfile.



## Q3.
    
### Frequency of exits
    The number of exits after immeditate reboot is approximately 500000-600000. 
    After each execution of the test file, the number of exits is found to be increasing at a rate of twenty thousands. 
