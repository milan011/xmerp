<?php

/* $Id: PDFInventoryPlanPageHeader.inc 3605 2010-07-11 20:59:10Z tim_schofield $*/
/*PDF page header for inventory planning report */

if ($PageNumber>1){
	$pdf->newPage();
}

$FontSize=10;
$YPos= $Page_Height-$Top_Margin;

$LeftOvers = $pdf->addTextWrap($Left_Margin,$YPos,300,$FontSize,$_SESSION['CompanyRecord']['coyname']);

$YPos -=$line_height;

$FontSize=10;

if (isset($_POST['SupplierID']) and $_POST['SupplierID']=="0"){ //no supplier selected its a stock category report
	$ReportTitle = _('Inventory Planning for Categories Between') . ' ' . $_POST['FromCriteria'] . ' ' . _('and') . ' ' . $_POST['ToCriteria'];
} else { //supplier selected its just planning for products from the supplier
	$ReportTitle = _('Inventory Planning for Products Category') . ' ' . $_POST['FromCriteria'];
}

if ($_POST['Location']=='All'){

	$LeftOvers = $pdf->addTextWrap($Left_Margin, $YPos,450,$FontSize, $ReportTitle . ' ' . _('for all stock locations'));

} else {

	$LeftOvers = $pdf->addTextWrap($Left_Margin, $YPos,450,$FontSize, $ReportTitle . ' ' . _('for stock at') . ' ' . $_POST['Location']);

}

$FontSize=8;
$LeftOvers = $pdf->addTextWrap($Page_Width-$Right_Margin-120,$YPos,120,$FontSize,_('Printed') . ': ' . Date($_SESSION['DefaultDateFormat']) . '   ' . _('Page') . ' ' . $PageNumber);

$YPos -=(2*$line_height);

/*Draw a rectangle to put the headings in     */

$pdf->line($Left_Margin, $YPos+$line_height,$Page_Width-$Right_Margin, $YPos+$line_height);
$pdf->line($Left_Margin, $YPos+$line_height,$Left_Margin, $YPos- $line_height);
$pdf->line($Left_Margin, $YPos- $line_height,$Page_Width-$Right_Margin, $YPos- $line_height);
$pdf->line($Page_Width-$Right_Margin, $YPos+$line_height,$Page_Width-$Right_Margin, $YPos- $line_height);

/*set up the headings */
$XPos = $Left_Margin+1;

$LeftOvers = $pdf->addTextWrap($XPos,$YPos,180,$FontSize,_('Item'),'centre');
$LeftOvers = $pdf->addTextWrap(160,$YPos,45,$FontSize,_('Description'),'centre');
$LeftOvers = $pdf->addTextWrap(270,$YPos,40,$FontSize,$Period_5_Name . ' ' . _('Qty5'),'centre');
$LeftOvers = $pdf->addTextWrap(307,$YPos,40,$FontSize,$Period_4_Name . ' ' . _('Qty4'),'centre');
$LeftOvers = $pdf->addTextWrap(348,$YPos,40,$FontSize,$Period_3_Name . ' ' . _('Qty3'),'centre');
$LeftOvers = $pdf->addTextWrap(389,$YPos,40,$FontSize,$Period_2_Name . ' ' . _('Qty2'),'centre');
$LeftOvers = $pdf->addTextWrap(430,$YPos,40,$FontSize,$Period_1_Name . ' ' . _('Qty1'),'centre');
$LeftOvers = $pdf->addTextWrap(471,$YPos,40,$FontSize,$Period_0_Name . ' ' . _('MTD'),'centre');

$stat=$_POST['NumberMonthsHolding'];
	if ($_POST['NumberMonthsHolding']>10){
		$NumberMonthsHolding=$_POST['NumberMonthsHolding']-10;
	}
	else{
		$NumberMonthsHolding=$_POST['NumberMonthsHolding'];

	}
$LeftOvers = $pdf->addTextWrap(512,$YPos,40,$FontSize,$NumberMonthsHolding . ' ' . _('ms stk'),'centre');
$LeftOvers = $pdf->addTextWrap(617,$YPos,40,$FontSize,_('QOH'),'centre');
$LeftOvers = $pdf->addTextWrap(648,$YPos,40,$FontSize,_('Cust Ords'),'centre');
$LeftOvers = $pdf->addTextWrap(694,$YPos,40,$FontSize,_('Splr Ords'),'centre');
$LeftOvers = $pdf->addTextWrap(735,$YPos,40,$FontSize,_('Sugg Ord'),'centre');

$YPos =$YPos - (2*$line_height);
$FontSize=8;
?>