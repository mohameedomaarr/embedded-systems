#!/bin/bash

# Bash Script to Analyze Network Traffic

# Input: Path to the Wireshark pcap file
read -p "Enter the path to the pcap file: " pcap_file

# Function to extract information from the pcap file
analyze_traffic() {
    echo "Analyzing traffic from $pcap_file..."

    # Total packets
    total_packets=$(tshark -r $pcap_file | wc -l)

    # Protocols
    http_packets=$(tshark -r $pcap_file -Y http | wc -l)
    https_packets=$(tshark -r $pcap_file -Y tls | wc -l)
    tcp_packets=$(tshark -r $pcap_file -Y tcp | wc -l)

    # Top Source IP Addresses
    top_source_ips=$(tshark -r $pcap_file -T fields -e ip.src | sort | uniq -c | sort -nr | head -n 5)

    # Top Destination IP Addresses
    top_dest_ips=$(tshark -r $pcap_file -T fields -e ip.dst | sort | uniq -c | sort -nr | head -n 5)

    # Output analysis summary
    echo "----- Network Traffic Analysis Report -----"
    echo "1. Total Packets: $total_packets"
    echo "2. Protocols:"
    echo "   - HTTP: $http_packets packets"
    echo "   - HTTPS/TLS: $https_packets packets"
    echo "   - TCP: $tcp_packets packets"
    echo ""
    echo "3. Top 5 Source IP Addresses:"
    echo "$top_source_ips"
    echo ""
    echo "4. Top 5 Destination IP Addresses:"
    echo "$top_dest_ips"
    echo ""
    echo "----- End of Report -----"
}

# Run the analysis function
analyze_traffic

